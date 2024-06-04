package com.aim.runners;

import com.aim.PlotType;
import com.aim.RunData;
import com.aim.TestFrame;
import com.aim.TestFrameConfig;
import com.aim.metaheuristics.singlepoint.lateacceptance.LateAcceptance;
import com.aim.metaheuristics.singlepoint.simulatedannealing.SimulatedAnnealing;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;
import uk.ac.nott.cs.aim.searchmethods.SearchMethod;
import uk.ac.nott.cs.aim.statistics.PlotData;
import uk.ac.nott.cs.aim.statistics.XBoxPlot;
import uk.ac.nott.cs.aim.statistics.XLineChart;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * 
 * @author Warren G. Jackson
 * 
 * Note - This will take longer than previous algorithms since
 * the termination criterion is evaluation-based (not time-based), hence the 
 * computationally expensive problem.copy() method significantly increases
 * the actual run time with only one evaluation being performed per copy.
 *
 */
public class Exercise2cRunner extends TestFrame {

	private final String BOXPLOT_TITLE;

	/**
	 * Choose whether to plot the progress plots for ALL, BEST, WORST, or BEST_AND_WORST trials.
	 * WARNING: Setting this to PlotType.ALL will take a while to render the progress plots!
	 */
	private static final PlotType PLOT_TYPE = PlotType.BEST_AND_WORST;

	/**
	 *
	 * @param config
	 */
	public Exercise2cRunner(TestFrameConfig config) {
		
		super(config);
		
		TestFrameConfig oTestConfiguration = getTestConfiguration();
		BOXPLOT_TITLE = "Results produced by " + config.getMethodName() + " for solving SAT instance "
				+ oTestConfiguration.getInstanceId() + " given " + oTestConfiguration.getRunTime() + " seconds over "
				+ oTestConfiguration.getTotalRuns() + " runs.";
	}

	@Override
	public void runTests() {

		// execute the experiments (single algorithm so ID is 0)
		List<RunData> oRunData = runExperimentsForHeuristicId(0);

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
			
			switch(PLOT_TYPE) {
			case ALL:
				oRunData.stream().filter(f -> f.getHeuristicId() == id).forEach(o -> {

					oProgressPlotData.add(new PlotData(o.getData(), String.format("Trial #%d", o.getTrialId())));
				});
				break;
			case BEST:
				addBestTrace(oRunData, oProgressPlotData, id);
				break;
			case WORST:
				addWorstTrace(oRunData, oProgressPlotData, id);
				break;
			case BEST_AND_WORST:
				addBestTrace(oRunData, oProgressPlotData, id);
				addWorstTrace(oRunData, oProgressPlotData, id);
				break;
			}

			// creates and shows the plot
			XLineChart.getPlotCreator().createChart(strTitle, strXLabel, strYLabel, oProgressPlotData);
		}
	}
	
	private void addBestTrace(List<RunData> oRunData, List<PlotData> oProgressPlotData, int id) {
		
		double best = oRunData.stream().filter(f -> f.getHeuristicId() == id).mapToDouble(RunData::getBestSolutionValue).min().getAsDouble();
		RunData data = oRunData.stream().filter(f -> f.getHeuristicId() == id).filter(f -> f.getBestSolutionValue() == best).findFirst().get();
		oProgressPlotData.add(new PlotData(data.getData(), String.format("Best Trial #%d", data.getTrialId())));
	}
	
	private void addWorstTrace(List<RunData> oRunData, List<PlotData> oProgressPlotData, int id) {
		
		double best = oRunData.stream().filter(f -> f.getHeuristicId() == id).mapToDouble(RunData::getBestSolutionValue).max().getAsDouble();
		RunData data = oRunData.stream().filter(f -> f.getHeuristicId() == id).filter(f -> f.getBestSolutionValue() == best).findFirst().get();
		oProgressPlotData.add(new PlotData(data.getData(), String.format("Worst Trial #%d", data.getTrialId())));
	}
	
	public List<RunData> runExperimentsForHeuristicId(int heuristicId) {
		
		long[] seeds = getExperimentalSeeds();
		
		Stream<RunData> dat = runUsingExperimentalParallelism(rangeAsStream(0, getTestConfiguration().getTotalRuns() - 1)).map( run -> {
			
			Random random = new Random(seeds[run]);
			SAT sat = new SAT(getTestConfiguration().getInstanceId(), getTestConfiguration().getRunTime(), random);
			ArrayList<Double> fitnessTrace = new ArrayList<Double>();
			
			double initialSolutionFitness = sat.getObjectiveFunctionValue(0);
			int listlen = ((Exercise2cTestFrameConfig)getTestConfiguration()).getListLength();
			SearchMethod searchMethod = new LateAcceptance(sat, random, listlen);
			
			double fitness = sat.getObjectiveFunctionValue(SATHeuristic.CURRENT_SOLUTION_INDEX);
			fitnessTrace.add(fitness);
			while(!sat.hasTimeExpired()) {
				
				fitnessTrace.add(searchMethod.run());
			}
			
			logResult(searchMethod.toString(), run, sat.getBestSolutionValue(), sat.getBestSolutionAsString());
			
			return new RunData(fitnessTrace, sat.getBestSolutionValue(), searchMethod.toString(), heuristicId, run, sat.getBestSolutionAsString());
		});
		
		return dat.collect(Collectors.toList());
	}
	
	public static void main(String [] args) {

		Exercise2cTestFrameConfig config = Exercise2cTestFrameConfig.getInstance();
		TestFrame runner = new Exercise2cRunner(config);
		runner.runTests();
	}
}
