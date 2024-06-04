package com.aim.metaheuristics.population.memetic;

import com.aim.metaheuristics.population.ParentSelection;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;

import java.util.Random;

/**
 * @author Warren G. Jackson
 */
public class RandomSelection extends ParentSelection {

	public RandomSelection(SAT problem, Random rng, int POPULATION_SIZE) {
		
		super(problem, rng, POPULATION_SIZE);
	}

	/**
	  * @return The index of the chosen parent solution.
	  *
	  * PSEUDOCODE
	  *
	  * INPUT: POPULATION_SIZE
	  * index = random \in population
	  * return index;
	  */
	public int parentSelection() {

		return rng.nextInt(POPULATION_SIZE);
	}
}
