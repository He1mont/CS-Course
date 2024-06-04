package com.aim.runners;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

import com.aim.RunData;
import com.aim.TestFrame;
import com.aim.TestFrameConfig;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;
import uk.ac.nott.cs.aim.statistics.PlotData;
import uk.ac.nott.cs.aim.statistics.XBoxPlot;
import uk.ac.nott.cs.aim.statistics.XLineChart;

/**
 * Runner class for lab exercise 1.
 *
 * @author Warren G. Jackson
 * @since 05/02/2024
 *
 */
public class Exercise1Runner extends TestFrame {
	
	private static final int NUMBER_OF_HEURISTICS_TO_TEST = 2;
	
	/*
	 * name to give to your box plot title
	 */
	private final String BOXPLOT_TITLE;

	public Exercise1Runner(Exercise1TestFrameConfig config) {

		super(config);
		
		TestFrameConfig oTestConfiguration = getTestConfiguration();
		BOXPLOT_TITLE = "Comparison of Heuristics A and B for instance "
		+ oTestConfiguration.getInstanceId() + " given " + oTestConfiguration.getRunTime() + " seconds over " + oTestConfiguration.getTotalRuns() + " runs.";
	}

	public void runTests() {

		// execute the experiments
		List<RunData> oRunData = runUsingExperimentalParallelism(rangeAsStream(0, NUMBER_OF_HEURISTICS_TO_TEST - 1))
				.map(this::runExperimentsForHeuristicId)
				.flatMap(Collection::stream)
				.toList();

		// generate boxplots
		List<PlotData> oPlotData = new ArrayList<PlotData>();
		
		// get a distinct list of heuristic IDs.
		List<Integer> oHeuristicIds = oRunData.stream().map(RunData::getHeuristicId).distinct().toList();
		
		// for each heuristic, collate and add the objective values of the best solutions found
		oHeuristicIds.forEach( id -> {
			
			List<Double> odResults = oRunData.stream()
					.filter(f->f.getHeuristicId() == id)
					.map(RunData::getBestSolutionValue)
					.collect(Collectors.toList());
			
			String strHeuristicName = oRunData.stream()
					.filter(f->f.getHeuristicId() == id)
					.findAny()
					.get()
					.getHeuristicName();
			
			oPlotData.add(new PlotData(odResults, strHeuristicName));
		});
		
		// create and show the plot
		XBoxPlot.getPlotCreator().createPlot(BOXPLOT_TITLE, "Heuristic", "Objective Value", oPlotData);
		
		/*
		 *  generate progress plots
		 */
		
		// create plots for each heuristic
		for(int id : oHeuristicIds) {
			
			// get the name of the heuristic with ID 'id'
			String strHeuristicName = oRunData.stream()
					.filter(f->f.getHeuristicId() == id)
					.findAny()
					.get()
					.getHeuristicName();

			// set up plot labels
			String strTitle = "Comparison of the fitness traces of " + strHeuristicName;
			String strXLabel = "Iteration";
			String strYLabel = "Objective value";
			
			// create a list of progress plots for the current heuristic
			List<PlotData> oProgressPlotData = new ArrayList<>();
			oRunData.stream()
				.filter(f->f.getHeuristicId() == id)
				.forEach( data -> {
				
					oProgressPlotData.add(new PlotData(data.getData(), String.format("Trial #%d", data.getTrialId())));
				});
			
			// creates and shows the plot
			XLineChart.getPlotCreator().createChart(strTitle, strXLabel, strYLabel, oProgressPlotData);
		}
		
	}
	
	public List<RunData> runExperimentsForHeuristicId(int heuristicId) {

		// runs the experiments over 'getTestConfiguration().getTotalRuns()' trials either synchronous or in parallel
		// as defined in ExperimentalSettings.java
		return runUsingExperimentalParallelism(rangeAsStream(0, getTestConfiguration().getTotalRuns() - 1))
				.map(run -> runExperiment(run, heuristicId))
				.collect(Collectors.toList());
	}

	public RunData runExperiment(int run, int heuristicId) {

		long[] seeds = getExperimentalSeeds();
		Random random = new Random(seeds[run]);
		
		TestFrameConfig oTestConfiguration = getTestConfiguration();
		SAT sat = new SAT(oTestConfiguration.getInstanceId(), oTestConfiguration.getRunTime(), random);
		ArrayList<Double> fitnessTrace = new ArrayList<Double>();

		SATHeuristic heuristic = Exercise1TestFrameConfig.getSATHeuristic(heuristicId, random);
		
		// record the objective value of the initial solution
		fitnessTrace.add(sat.getObjectiveFunctionValue(SATHeuristic.CURRENT_SOLUTION_INDEX));
		
		// continually apply the local search heuristic until the execution time expires
		while (!sat.hasTimeExpired()) {

			// apply DBHC/SDHC to the solution-in-hand
			heuristic.applyHeuristic(sat);
			
			// evaluate the cost of the solution-in-hand
			double fitness = sat.getObjectiveFunctionValue(SATHeuristic.CURRENT_SOLUTION_INDEX);
			
			// add data to progress plot
			if (!sat.hasTimeExpired()) {
				fitnessTrace.add(fitness);
			}
		}

		logResult(heuristic.getHeuristicName(), run, sat.getBestSolutionValue(), sat.getBestSolutionAsString());

		return new RunData(fitnessTrace, sat.getBestSolutionValue(), heuristic.getHeuristicName(), heuristicId, run,
				sat.getBestSolutionAsString());
	}

	public static void main(String[] args) {
		Exercise1TestFrameConfig config = Exercise1TestFrameConfig.getInstance();
		TestFrame runner = new Exercise1Runner(config);
		runner.runTests();
	}
}
