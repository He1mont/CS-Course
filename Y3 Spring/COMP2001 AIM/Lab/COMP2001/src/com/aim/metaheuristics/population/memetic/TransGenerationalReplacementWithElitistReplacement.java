
package com.aim.metaheuristics.population.memetic;

import java.util.stream.IntStream;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.genetics.PopulationReplacement;

public class TransGenerationalReplacementWithElitistReplacement extends PopulationReplacement {

	@Override
	protected int[] getNextGeneration(SAT oProblem, int iPopulationSize) {
		// find the index with the best solution
		int best = 0;
		for (int i = 0; i < iPopulationSize * 2; i++) {
			if (oProblem.getObjectiveFunctionValue(i) < oProblem.getObjectiveFunctionValue(best)) {
				best = i;
			}
		}
		// generate indices of the next generation
		int[] ret = new int[iPopulationSize];
		for (int i = 0; i < iPopulationSize; i++) {
			ret[i] = iPopulationSize + i;
		}
		// if the solution is not among offsprings
		if (best < iPopulationSize) {
			// find the index with the worst solution among offsprings
			int worst = iPopulationSize;
			for (int i = iPopulationSize; i < iPopulationSize * 2; i++) {
				if (oProblem.getObjectiveFunctionValue(i) > oProblem.getObjectiveFunctionValue(worst)) {
					worst = i;
				}
			}
			// replace worst with best
			ret[worst - iPopulationSize] = best;
		}
		return ret;
	}

}
