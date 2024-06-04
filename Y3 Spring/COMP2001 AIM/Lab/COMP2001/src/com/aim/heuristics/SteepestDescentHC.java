package com.aim.heuristics;


import java.util.Random;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;


public class SteepestDescentHC extends SATHeuristic {

	public SteepestDescentHC(Random random) {
		
		super(random);
	}

	/**
	  *
	  * @param problem The problem to be solved.
	  */
	public void applyHeuristic(SAT problem) {
		int bestIndex = -1;
		boolean improved = false;
//		problem.createRandomSolution(CURRENT_SOLUTION_INDEX);
		double best = problem.getObjectiveFunctionValue(CURRENT_SOLUTION_INDEX);

		for (int i = 0; i < problem.getNumberOfVariables(); i++) {
			problem.bitFlip(i, CURRENT_SOLUTION_INDEX);
			double tmp = problem.getObjectiveFunctionValue(CURRENT_SOLUTION_INDEX);
			if (tmp < best) {
				bestIndex = i;
				improved = true;
				best = tmp;
			}
			problem.bitFlip(i, CURRENT_SOLUTION_INDEX);
		}
		if (improved)
			problem.bitFlip(bestIndex, CURRENT_SOLUTION_INDEX);

	}

	public String getHeuristicName() {
		
		return "Steepest Descent HC";
	}

}
