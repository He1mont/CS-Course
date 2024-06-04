package com.aim.metaheuristics.population.heuristics;

import java.util.Random;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.genetics.PopulationHeuristic;

/**
 * 
 * @author Warren G. Jackson
 *
 */
public class BitMutation extends PopulationHeuristic {
	
	/**
	 * 
	 */
	private double m_mutationRate;
	
	/**
	 * 
	 */
	private final int m_variables;

	/**
	 * 
	 * @param oProblem
	 * @param oRandom
	 */
	public BitMutation(SAT oProblem, Random oRandom) {
		super(oProblem, oRandom);

		this.m_variables = oProblem.getNumberOfVariables();
		setMutationRate(1);
	}

	/**
	 * 
	 * @param iIntensityOfMutation
	 */
	public void setMutationRate(int iIntensityOfMutation) {
		
		this.m_mutationRate = ((double) iIntensityOfMutation / this.m_variables);
	}

	@Override
	public void applyHeuristic(int iSolutionMemoryIndex) {
		
		for (int i = 0; i < this.problem.getNumberOfVariables(); i++) {
			
			if (this.random.nextDouble() < this.m_mutationRate) {
				
				this.problem.bitFlip(i, iSolutionMemoryIndex);
			}
		}
	}
}
