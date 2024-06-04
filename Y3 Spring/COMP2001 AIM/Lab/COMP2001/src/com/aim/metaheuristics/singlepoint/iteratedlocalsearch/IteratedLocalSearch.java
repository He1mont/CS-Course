package com.aim.metaheuristics.singlepoint.iteratedlocalsearch;

import java.util.Random;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;
import uk.ac.nott.cs.aim.searchmethods.SinglePointSearchMethod;

	
public class IteratedLocalSearch extends SinglePointSearchMethod {

	// local search / intensification heuristic
	private SATHeuristic oLocalSearchHeuristic;
	
	// mutation / perturbation heuristic
	private SATHeuristic oMutationHeuristic;
	
	// iom parameter setting
	private int iIntensityOfMutation;
	
	// dos parameter setting
	private int iDepthOfSearch;
	
	/**
	 * 
	 * @param oProblem The problem to be solved.
	 * @param oRandom The random number generator, use this one, not your own!
	 * @param oMutationHeuristic The mutation heuristic.
	 * @param oLocalSearchHeuristic The local search heuristic.
	 * @param iIntensityOfMutation The parameter setting for intensity of mutation.
	 * @param iDepthOfSearch The parameter setting for depth of search.
	 */
	public IteratedLocalSearch(SAT oProblem, Random oRandom, SATHeuristic oMutationHeuristic, 
			SATHeuristic oLocalSearchHeuristic, int iIntensityOfMutation, int iDepthOfSearch) {
		
		super(oProblem, oRandom);
		
		this.oMutationHeuristic = oMutationHeuristic;
		this.oLocalSearchHeuristic = oLocalSearchHeuristic;
		this.iIntensityOfMutation = iIntensityOfMutation;
		this.iDepthOfSearch = iDepthOfSearch;
	}

	protected void runMainLoop() {
		for (int i = 0; i < iIntensityOfMutation; i++) {
			oMutationHeuristic.applyHeuristic(problem);
		}
		for (int i = 0; i < iDepthOfSearch; i++) {
			oLocalSearchHeuristic.applyHeuristic(problem);
		}
		double prev = problem.getObjectiveFunctionValue(BACKUP_SOLUTION_INDEX);
		double curr = problem.getObjectiveFunctionValue(CURRENT_SOLUTION_INDEX);

		if (curr < prev) { 		// accept this improved solution
			problem.copySolution(CURRENT_SOLUTION_INDEX, BACKUP_SOLUTION_INDEX);
		} else {				// reject this solution
			problem.copySolution(BACKUP_SOLUTION_INDEX, CURRENT_SOLUTION_INDEX);
		}
	}
	
	public String toString() {
		
		return "Iterated Local Search";
	}
}
