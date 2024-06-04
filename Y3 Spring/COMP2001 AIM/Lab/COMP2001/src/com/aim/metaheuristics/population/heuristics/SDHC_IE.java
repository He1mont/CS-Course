package com.aim.metaheuristics.population.heuristics;

import java.util.Random;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;

public class SDHC_IE extends SteepestDescentHillClimbing {
	public SDHC_IE(SAT oProblem, Random oRandom) {
		super(oProblem, oRandom);
	}

	public boolean acceptMove(double dCurrentSolutionFitness, double dCandidateSolutionFitness) {
		return dCandidateSolutionFitness <= dCurrentSolutionFitness;
	}
}
