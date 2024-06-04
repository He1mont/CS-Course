package com.aim.metaheuristics.population.memetic;

import java.util.Random;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.genetics.CrossoverHeuristic;


public class UniformXO extends CrossoverHeuristic {

	public UniformXO(SAT problem, Random random) {
		
		super(problem, random);
	}

	public void applyHeuristic(int parent1Index, int parent2Index, int child1Index, int child2Index) {

		problem.copySolution(parent1Index, child1Index);
		problem.copySolution(parent2Index, child2Index);

		for (int i = 0; i < problem.getNumberOfVariables(); i++) {
			if (random.nextDouble() < 0.5) {
				problem.exchangeBits(child1Index, child2Index, i);
			}
		}

	}
}
