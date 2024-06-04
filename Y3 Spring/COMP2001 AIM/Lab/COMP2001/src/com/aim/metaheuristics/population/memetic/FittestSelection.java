package com.aim.metaheuristics.population.memetic;

import com.aim.metaheuristics.population.ParentSelection;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;

import java.util.Random;

/**
 * @author Warren G. Jackson
 */
public class FittestSelection extends ParentSelection {

	public FittestSelection(SAT problem, Random rng, int POPULATION_SIZE) {
		
		super(problem, rng, POPULATION_SIZE);
	}

	public int parentSelection() {

		if (POPULATION_SIZE <= 0 ) {
			System.out.println("Empty Population Size");
			System.exit(-1);
		}

		int best = 0;
		for (int i = 1; i < POPULATION_SIZE; i++) {
			if (problem.getObjectiveFunctionValue(i) < problem.getObjectiveFunctionValue(best)) {
				best = i;
			}
		}
		return best;
	}
}
