package com.aim.metaheuristics.population.heuristics;

import java.util.Random;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;

public class SDHC_OI extends SteepestDescentHillClimbing {
	public SDHC_OI(SAT oProblem, Random oRandom) {
		super(oProblem, oRandom);
	}

	public boolean acceptMove(double dCurrentSolutionFitness, double dCandidateSolutionFitness) {
		return dCandidateSolutionFitness < dCurrentSolutionFitness;
	}
}
