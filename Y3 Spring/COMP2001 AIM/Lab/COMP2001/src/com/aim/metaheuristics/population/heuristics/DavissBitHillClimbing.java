package com.aim.metaheuristics.population.heuristics;

import java.util.Random;
import java.util.stream.IntStream;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.helperfunctions.ArrayMethods;
import uk.ac.nott.cs.aim.satheuristics.genetics.PopulationHeuristic;

public abstract class DavissBitHillClimbing extends PopulationHeuristic {

	public DavissBitHillClimbing(SAT oProblem, Random oRandom) {
		
		super(oProblem, oRandom);
	}

	public void applyHeuristic(int iSolutionMemoryIndex) {
		
		int[] variableIndices = IntStream.range(0, this.problem.getNumberOfVariables()).toArray();
		int[] perm = ArrayMethods.shuffle(variableIndices, this.random);
		
		double currentCost = this.problem.getObjectiveFunctionValue(iSolutionMemoryIndex);
		
		for (int j = 0; j < perm.length; j++) {
			
			this.problem.bitFlip(perm[j], iSolutionMemoryIndex);
			double candidateCost = this.problem.getObjectiveFunctionValue(iSolutionMemoryIndex);
			
			if (acceptMove(currentCost, candidateCost)) {
				
				currentCost = candidateCost;
				
			} else {
				
				this.problem.bitFlip(perm[j], iSolutionMemoryIndex);
			}
		}
	}

	public abstract boolean acceptMove(double paramDouble1, double paramDouble2);
}
