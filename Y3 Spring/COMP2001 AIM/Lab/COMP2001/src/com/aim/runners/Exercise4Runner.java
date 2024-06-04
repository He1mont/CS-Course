package com.aim.runners;


import AbstractClasses.HyperHeuristic;
import AbstractClasses.ProblemDomain;
import BinPacking.BinPacking;
import SAT.SAT;
import com.aim.hyperheuristics.RLILS_AM_HH;
import travelingSalesmanProblem.TSP;


public class Exercise4Runner {
	
	final Exercise4TestFrameConfig config;
	
	final int TOTAL_RUNS;
	final String[] DOMAINS;
	final int[][] INSTANCE_IDs;
	final long RUN_TIME;
	final long[] SEEDS;
	final int defaultScore, lowerBound, upperBound;
	
	public Exercise4Runner(Exercise4TestFrameConfig config) {
	
		this.config = config;
		
		this.TOTAL_RUNS = config.getTotalRuns();
		this.DOMAINS = config.PROBLEM_DOMAINS;
		this.INSTANCE_IDs = config.getInstanceIDs();
		this.SEEDS = config.getSeeds();
		this.RUN_TIME = config.getRunTime();
		this.defaultScore = config.DEFAULT_SCORE;
		this.lowerBound = config.LOWER_BOUND;
		this.upperBound = config.UPPER_BOUND;
	}

	public void runTests() {
		
		String hyperHeuristicName = null;
		String problemDomain = null;
		double[] bestSolutionFitness_s = new double[TOTAL_RUNS];
		System.out.println("Problem\tInstance\tTrial\tBest_Solution_Value");
		
		for(int domain = 0; domain < DOMAINS.length; domain++) {

			for(int instance = 0; instance < INSTANCE_IDs[domain].length; instance++) {
				
				int instanceID = INSTANCE_IDs[domain][instance];
				
				for(int run = 0; run < TOTAL_RUNS; run++) {
					
					long seed = SEEDS[run];
					
					HyperHeuristic hh = new RLILS_AM_HH(seed, defaultScore, lowerBound, upperBound);
					ProblemDomain problem = getNewDomain(DOMAINS[domain], seed);
					problem.loadInstance(instanceID);
					hh.setTimeLimit(RUN_TIME);	
					hh.loadProblemDomain(problem);
					hh.run();
					
					hyperHeuristicName = hh.toString();
					problemDomain = problem.getClass().getName().split("\\.")[1];
					bestSolutionFitness_s[run] = hh.getBestSolutionValue();
					System.out.printf("%s\t%d\t%d\t%f%n", problemDomain, instanceID, run, hh.getBestSolutionValue());
				}
				
				//print or save results
				StringBuilder sb = new StringBuilder();
				sb.append(hyperHeuristicName).append(",").append(RUN_TIME).append(",").append(problemDomain).append(",").append(instanceID);
				for(double ofv : bestSolutionFitness_s) {
					sb.append(",").append(ofv);
				}
				
				config.saveData(hyperHeuristicName + ".csv", sb.toString());
			}
		}
	}
	
	public ProblemDomain getNewDomain(String domain, long seed) {
		
		return switch (domain.toUpperCase()) {
            case "SAT" -> new SAT(seed);
            case "BP" -> new BinPacking(seed);
            case "TSP" -> new TSP(seed);
            default -> null;
        };
	}
	
	public static void main(String [] args) {
		
		new Exercise4Runner(new Exercise4TestFrameConfig()).runTests();
	}
}
