
package com.aim.metaheuristics.population.memetic;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.genetics.PopulationReplacement;

import java.util.stream.IntStream;

public class BasicReplacement extends PopulationReplacement {

	@Override
	protected int[] getNextGeneration(SAT oProblem, int iPopulationSize) {

		int[] ret = new int[iPopulationSize];
		for (int i = 0; i < iPopulationSize; i++) {
			ret[i] = i + iPopulationSize;
		}
		return ret;
	}

}
