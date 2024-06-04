package com.aim.metaheuristics.population.heuristics;

import java.util.Random;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;

public class DBHC_IE extends DavissBitHillClimbing {
	
	public DBHC_IE(SAT oProblem, Random oRandom) {
		
		super(oProblem, oRandom);
	}

	public boolean acceptMove(double dCurrentSolutionFitness, double dCandidateSolutionFitness) {
		
		return dCandidateSolutionFitness <= dCurrentSolutionFitness;
	}
}
