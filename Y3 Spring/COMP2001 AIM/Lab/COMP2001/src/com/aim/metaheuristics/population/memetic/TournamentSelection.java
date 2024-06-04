package com.aim.metaheuristics.population.memetic;

import java.util.Random;
import java.util.stream.IntStream;

import com.aim.metaheuristics.population.ParentSelection;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.helperfunctions.ArrayMethods;

/**
 * @author Warren G. Jackson
 */
public class TournamentSelection extends ParentSelection {

	private final int tournamentSize;

	public TournamentSelection(SAT problem, Random rng, int POPULATION_SIZE, int tournamentSize) {
		
		super(problem, rng, POPULATION_SIZE);
		this.tournamentSize = tournamentSize;
	}

	public int parentSelection() {

		int best = 0;

		for (int i = 0; i < tournamentSize; i++) {
			int index = rng.nextInt(POPULATION_SIZE);
			if (problem.getObjectiveFunctionValue(index) < problem.getObjectiveFunctionValue(best)) {
				best = index;
			}
		}
		return best;
	}
}
