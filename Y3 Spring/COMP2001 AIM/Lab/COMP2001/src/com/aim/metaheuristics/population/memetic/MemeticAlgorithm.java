package com.aim.metaheuristics.population.memetic;

import java.util.Random;

import com.aim.metaheuristics.population.ParentSelection;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.genetics.CrossoverHeuristic;
import uk.ac.nott.cs.aim.satheuristics.genetics.PopulationHeuristic;
import uk.ac.nott.cs.aim.satheuristics.genetics.PopulationReplacement;
import uk.ac.nott.cs.aim.searchmethods.PopulationBasedSearchMethod;

/**
 * Memetic Algorithm ( local search should to be added per the report exercise ).
 * 
 * @author Warren G. Jackson
 *
 */
public class MemeticAlgorithm extends PopulationBasedSearchMethod {

	private static final int TOURNAMENT_SIZE = 3;

	private final CrossoverHeuristic crossover;

	private final PopulationHeuristic mutation;

	private final PopulationHeuristic localSearch;

	private final PopulationReplacement replacement;

	private final ParentSelection p1Selection;

	private final ParentSelection p2Selection;

	public MemeticAlgorithm(SAT problem, Random rng, int populationSize, CrossoverHeuristic crossover, 
			PopulationHeuristic mutation, PopulationHeuristic localSearch, ParentSelection p1Selection,
			ParentSelection p2Selection, PopulationReplacement replacement) {
		
		super(problem, rng, populationSize);
		
		this.crossover = crossover;
		this.mutation = mutation;
		this.localSearch = localSearch;
		this.replacement = replacement;

		this.p1Selection = p1Selection;
		this.p2Selection = p2Selection;
	}

	public void runMainLoop() {

		for(int iIterationCount = 0; iIterationCount < POPULATION_SIZE; iIterationCount += 2) {
			// Mate Selection
			int p1 = p1Selection.parentSelection();
			int p2 = p2Selection.parentSelection();
			if (p1 == p2) {
				p2 = (p2 + 1) % POPULATION_SIZE;
			}
			// Crossover
			int c1 = iIterationCount + POPULATION_SIZE;
			int c2 = iIterationCount + POPULATION_SIZE + 1;
			crossover.applyHeuristic(p1, p2, c1, c2);
			// Mutation
			mutation.applyHeuristic(c1);
			mutation.applyHeuristic(c2);
			// Hill Climbing
			localSearch.applyHeuristic(c1);
			localSearch.applyHeuristic(c2);
		}
		replacement.doReplacement(problem, POPULATION_SIZE);
	}
	
	@Override
	public String toString() {
		
		return "Memetic Algorithm";
	}
}
