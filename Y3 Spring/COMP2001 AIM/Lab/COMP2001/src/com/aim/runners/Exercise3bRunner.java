package com.aim.runners;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;
import java.util.stream.IntStream;

import com.aim.TestFrame;
import com.aim.TestFrameConfig;

import com.aim.metaheuristics.population.heuristics.*;
import com.aim.metaheuristics.population.memetic.*;
import com.aim.metaheuristics.population.multimeme.MultiMeme;
//import com.aim.metaheuristics.population.multimeme.MultiMemeExtended;
import com.aim.metaheuristics.population.multimeme.SimpleInheritanceMethod;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.genetics.PopulationHeuristic;
import uk.ac.nott.cs.aim.statistics.PlotData;
import uk.ac.nott.cs.aim.statistics.XBoxPlot;

public class Exercise3bRunner extends TestFrame {

	private final Object best_lock = new Object();
	private final Object output_lock = new Object();

	public Exercise3bRunner(Exercise3bTestFrameConfig config) {
		super(config);
	}
	
	public void runTests() {
		
		Exercise3bTestFrameConfig config = (Exercise3bTestFrameConfig)getTestConfiguration();
		double[] data = new double[config.getTotalRuns()];
		long[] SEEDS = getExperimentalSeeds();

		ArrayList<Double> runScores = new ArrayList<Double>();

		final double[] bestFoundCost = {Double.MAX_VALUE};
		final String[] bestFoundRepresentation = {null};

		List<Double> costs = IntStream.range(0, config.getTotalRuns()).parallel().boxed().map(trial -> {

			//generation based termination
			Random random = new Random(SEEDS[trial]);

			SAT sat = new SAT(config.getInstanceId(), config.getRunTime(), random, config.getPopulationSize(), config.getMemeCount(), config.getOptionsPerMeme());

			ArrayList<ArrayList<Long>> memeUsage = new ArrayList<ArrayList<Long>>();

			//initialise allele counters to 0
			for(int i = 0; i < config.getMemeCount(); i++) {

				memeUsage.add(i, new ArrayList<Long>());
				for(int j = 0; j < config.getOptionsPerMeme()[i]; j++) {

					memeUsage.get(i).add(j, 0L);
				}
			}

			LinkedList<ArrayList<Double>> fitnessTrace = new LinkedList<ArrayList<Double>>();
			for(int i = 0; i < config.getPopulationSize(); i++) {
				fitnessTrace.add(new ArrayList<Double>());
			}

			// create a MultiMeme dependent upon default configurations
			MultiMeme mma = null;
			if(config.OPERATOR_MODE == Exercise3bTestFrameConfig.OperatorMode.BASIC) {

				mma = new MultiMeme(sat,
						random,
						config.getPopulationSize(),
						config.INNOVATION_RATE,
						new PTX1(sat, random), // crossover
						new BitMutation(sat, random), // mutation
						new BasicReplacement(), // replacement
						new RandomSelection(sat, random, config.POP_SIZE), // parent selection
						new FittestSelection(sat, random, config.POP_SIZE), // parent selection
						new SimpleInheritanceMethod(sat, random), // memeplex inheritance
						new PopulationHeuristic[] { // create mapping for local search operators used for meme in meme index 1
								new DBHC_OI(sat, random), // [0]
								new DBHC_IE(sat, random), // [1]
								new SDHC_OI(sat, random), // [2]
								new SDHC_IE(sat, random)  // [3]
						});

			} else if(config.OPERATOR_MODE == Exercise3bTestFrameConfig.OperatorMode.ADVANCED) {

				mma = new MultiMeme(sat,
						random,
						config.getPopulationSize(),
						config.INNOVATION_RATE,
						new PTX1(sat, random), // crossover
						new BitMutation(sat, random), // mutation
						new TransGenerationalReplacementWithElitistReplacement(), // replacement
						new TournamentSelection(sat, random, config.getPopulationSize(), config.TOURNAMENT_SIZE), // parent selection
						new TournamentSelection(sat, random, config.getPopulationSize(), config.TOURNAMENT_SIZE), // parent selection
						new SimpleInheritanceMethod(sat, random), // memeplex inheritance
						new PopulationHeuristic[] { // create mapping for local search operators used for meme in meme index 1
								new DBHC_OI(sat, random), // [0]
								new DBHC_IE(sat, random), // [1]
								new SDHC_OI(sat, random), // [2]
								new SDHC_IE(sat, random)  // [3]
						});

			} else if (config.OPERATOR_MODE == Exercise3bTestFrameConfig.OperatorMode.CUSTOM) {

				mma = new MultiMeme(sat, random, config.getPopulationSize(), config.INNOVATION_RATE);

			} else {

				System.err.println("Invalid operator configuration... Exiting.");
				System.exit(0);
			}



			int count = 0;
			while(!sat.hasTimeExpired() && count <= config.MAX_GENERATIONS) {

//				sat.copySolution(0, 1);
//				sat.copySolution(1, 0);

				mma.run();

				//add all of population
				PriorityQueue<Double> pq = new PriorityQueue<>();
				for(int i = 0; i < config.getPopulationSize(); i++) {
					pq.add(sat.getObjectiveFunctionValue(i));
				}

				for(int i = 0; i < config.getPopulationSize(); i++) {
					fitnessTrace.get(i).add(pq.remove());
				}

				for(int i = 0; i < config.getMemeCount(); i++) {

					for(int j = 0; j < config.getPopulationSize(); j++) {
						int allele = sat.getMeme(j, i).getMemeOption();
						long c = memeUsage.get(i).get(allele);
						memeUsage.get(i).set(allele, c + 1);
					}
				}

				count++;
			}

			double currentBestSolution = sat.getBestSolutionValue();
			data[trial] = currentBestSolution;
			runScores.add(currentBestSolution);

			System.out.println("Heuristic: " + mma.toString());
			System.out.println("Run ID: " + trial);
			System.out.println("Best Solution Value: " + sat.getBestSolutionValue());
			System.out.println("Best Solution: " + sat.getBestSolutionAsString());

			for(int i = 0; i < config.getMemeCount(); i++) {

				System.out.println("MEME " + i + ":");
				for(int j = 0; j < config.getOptionsPerMeme()[i]; j++) {

					System.out.println("Allele " + j + " = " + memeUsage.get(i).get(j));
				}
			}

			System.out.println();

			synchronized (best_lock) {

				// ugly java lambda hack, never copy this... this is only safe due to the syncrhonisation!
				if(sat.getBestSolutionValue() < bestFoundCost[0]) {

					bestFoundCost[0] = sat.getBestSolutionValue();
					bestFoundRepresentation[0] = sat.getBestSolutionAsString();
				}
			}

			synchronized (output_lock) {


				//print or save results
				StringBuilder sb = new StringBuilder();
				sb.append(config.INNOVATION_RATE + ",").append(config.getRunTime()).append(",").append(config.getInstanceId());
				for(double ofv : runScores) {
					sb.append(",").append(ofv);
				}

				sb.append(",").append(bestFoundRepresentation[0]);

				System.out.println("Best Solution :" + bestFoundRepresentation[0]);
				saveData(config.getTotalRuns() + "Runs.csv", sb.toString());

			}

			return sat.getBestSolutionValue();

		}).toList();

		List<PlotData> oPlotData = new ArrayList<>();
		oPlotData.add(new PlotData(costs, "MMA"));
		costs.forEach(str -> {
			System.out.println(str);
		});

		XBoxPlot.getPlotCreator().createPlot(config.getBoxPlotTitle(), "Heuristic", "Objective Value", oPlotData);
	}
	
	private void saveData(String filePath, String data) {
		
		Path path = Paths.get("./" + filePath);
		if(!Files.exists(path)) {
			try {
				Files.createFile(path);
				TestFrameConfig CFG = getTestConfiguration();
				
				//add header
				StringBuilder header = new StringBuilder("Heuristic,Innovation Rate,Run Time,Instance ID");
				for(int i = 0; i < CFG.getTotalRuns(); i++) {
					
					header.append(",").append(i);
				}
				
				header.append(",Best Solution As String");
				
				Files.write(path, (header + "\r\n" + data).getBytes());
				
			} catch (IOException e) {
				System.err.println("Could not create file at " + path.toAbsolutePath());
				System.err.println("Printing data to screen instead...");
				System.out.println(data);
			}
			
		} else {
			
			try {
				byte[] currentData = Files.readAllBytes(path);
				data = "\r\n" + data;
				byte[] newData = data.getBytes();
				byte[] writeData = new byte[currentData.length + newData.length];
				System.arraycopy(currentData, 0, writeData, 0, currentData.length);
				System.arraycopy(newData, 0, writeData, currentData.length, newData.length);
				Files.write(path, writeData);
				
			} catch (IOException e) {
				System.err.println("Could not create file at " + path.toAbsolutePath());
				System.err.println("Printing data to screen instead...");
				System.out.println(data);
			}
			
		}
		
	}
	
	public static void main(String [] args) {
		
		Exercise3bTestFrameConfig config = Exercise3bTestFrameConfig.getInstance();
		TestFrame runner = new Exercise3bRunner(config);
		runner.runTests();
	}
}
