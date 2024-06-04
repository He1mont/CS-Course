package com.aim.runners;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import com.aim.RunData;
import com.aim.TestFrame;
import com.aim.TestFrameConfig;
import com.aim.heuristics.DavissBitHC;

import com.aim.metaheuristics.singlepoint.iteratedlocalsearch.IteratedLocalSearch;
import com.aim.pseudorandom.RandomBitFlipHeuristic;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;
import uk.ac.nott.cs.aim.searchmethods.SearchMethod;
import uk.ac.nott.cs.aim.statistics.PlotData;
import uk.ac.nott.cs.aim.statistics.XBoxPlot;
import uk.ac.nott.cs.aim.statistics.XLineChart;

public class Exercise2aRunner extends TestFrame {

	private static final int HEURISTIC_TESTS = 1;

	/*
	 * name to give to your box plot title
	 */
	private final String BOXPLOT_TITLE;

	private final int depthOfSearch;

	private final int intensityOfMutation;

	public Exercise2aRunner(Exercise2aTestFrameConfig config) {

		super(config);

		this.depthOfSearch = config.depthOfSearch;
		this.intensityOfMutation = config.intensityOfMutation;

		TestFrameConfig oTestConfiguration = getTestConfiguration();
		BOXPLOT_TITLE = "Results produced by " + config.getMethodName() + " for solving SAT instance "
				+ oTestConfiguration.getInstanceId() + " given " + oTestConfiguration.getRunTime() + " seconds over "
				+ oTestConfiguration.getTotalRuns() + " runs.";

	}

	public void runTests() {

		// execute the experiments
		List<RunData> oRunData = runUsingExperimentalParallelism(rangeAsStream(0, HEURISTIC_TESTS - 1))
				.map(this::runExperimentsForHeuristicId).flatMap(Collection::stream).collect(Collectors.toList());

		/*
		 * generate boxplots
		 */
		List<PlotData> oPlotData = new ArrayList<PlotData>();

		// get a distinct list of heuristic IDs.
		List<Integer> oHeuristicIds = oRunData.stream().map(RunData::getHeuristicId).distinct()
				.collect(Collectors.toList());

		// for each heuristic, collate and add the objective values of the best
		// solutions found
		oHeuristicIds.forEach(id -> {

			List<Double> odResults = oRunData.stream().filter(f -> f.getHeuristicId() == id)
					.map(RunData::getBestSolutionValue).collect(Collectors.toList());

			String strHeuristicName = oRunData.stream().filter(f -> f.getHeuristicId() == id).findAny().get()
					.getHeuristicName();

			oPlotData.add(new PlotData(odResults, strHeuristicName));
		});

		// create and show the plot
		XBoxPlot.getPlotCreator().createPlot(BOXPLOT_TITLE, "Heuristic", "Objective Value", oPlotData);

		/*
		 * generate progress plots
		 */

		// create plots for each heuristic
		for (int id : oHeuristicIds) {

			// get the name of the heuristic with ID 'id'
			String strHeuristicName = oRunData.stream().filter(f -> f.getHeuristicId() == id).findAny().get()
					.getHeuristicName();

			// set up plot labels
			String strTitle = "Comparison of the fitness traces of " + strHeuristicName;
			String strXLabel = "Iteration";
			String strYLabel = "Objective value";

			// create a list of progress plots for the current heuristic
			List<PlotData> oProgressPlotData = new ArrayList<>();
			oRunData.stream().filter(f -> f.getHeuristicId() == id).forEach(data -> {

				oProgressPlotData.add(new PlotData(data.getData(), String.format("Trial #%d", data.getTrialId())));
			});

			// creates and shows the plot
			XLineChart.getPlotCreator().createChart(strTitle, strXLabel, strYLabel, oProgressPlotData);
		}
	}

	public List<RunData> runExperimentsForHeuristicId(int heuristicId) {

		long[] seeds = getExperimentalSeeds();
		
		Stream<RunData> dat = runUsingExperimentalParallelism(rangeAsStream(0, getTestConfiguration().getTotalRuns() - 1)).map(run -> {

			Random random = new Random(seeds[run]);
			SAT sat = new SAT(getTestConfiguration().getInstanceId(), getTestConfiguration().getRunTime(), random);
			ArrayList<Double> fitnessTrace = new ArrayList<Double>();

			SATHeuristic ls = new DavissBitHC(random);
			SATHeuristic mtn = new RandomBitFlipHeuristic(random);
			SearchMethod searchMethod = new IteratedLocalSearch(sat, random, mtn, ls, intensityOfMutation,
					depthOfSearch);

			fitnessTrace.add(sat.getObjectiveFunctionValue(SATHeuristic.CURRENT_SOLUTION_INDEX));
			while (!sat.hasTimeExpired()) {

				searchMethod.run();
				double fitness = sat.getObjectiveFunctionValue(SATHeuristic.CURRENT_SOLUTION_INDEX);
				fitnessTrace.add(fitness);
			}

			logResult(searchMethod.toString(), run, sat.getBestSolutionValue(), sat.getBestSolutionAsString());

			return new RunData(fitnessTrace, sat.getBestSolutionValue(), searchMethod.toString(), heuristicId, run,
					sat.getBestSolutionAsString());
		});

		return dat.collect(Collectors.toList());
	}

	public static void main(String[] args) {

		Exercise2aTestFrameConfig config = Exercise2aTestFrameConfig.getInstance();
		TestFrame oTestFrame = new Exercise2aRunner(config);
		oTestFrame.runTests();
	}
}
