package com.aim.metaheuristics.population.heuristics;

import java.util.Random;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.genetics.PopulationHeuristic;

public abstract class SteepestDescentHillClimbing extends PopulationHeuristic {
	public SteepestDescentHillClimbing(SAT oProblem, Random oRandom) {
		super(oProblem, oRandom);
	}

	public void applyHeuristic(int iSolutionMemoryIndex) {
		double d1;
		double d2 = d1 = this.problem.getObjectiveFunctionValue(iSolutionMemoryIndex);
		int i = -1;
		for (int j = 0; j < this.problem.getNumberOfVariables(); j++) {
			this.problem.bitFlip(j, iSolutionMemoryIndex);
			d1 = this.problem.getObjectiveFunctionValue(iSolutionMemoryIndex);
			if (acceptMove(d2, d1)) {
				i = j;
				d2 = d1;
			}
			this.problem.bitFlip(j, iSolutionMemoryIndex);
		}
		if (i != -1) {
			this.problem.bitFlip(i, iSolutionMemoryIndex);
		}
	}

	public abstract boolean acceptMove(double paramDouble1, double paramDouble2);
}
