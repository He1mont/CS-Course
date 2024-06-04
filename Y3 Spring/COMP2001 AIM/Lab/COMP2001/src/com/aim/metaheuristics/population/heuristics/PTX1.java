package com.aim.metaheuristics.population.heuristics;

import java.util.Random;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.genetics.CrossoverHeuristic;

public class PTX1 extends CrossoverHeuristic {
	public PTX1(SAT oProblem, Random oRandom) {
		super(oProblem, oRandom);
	}

	public void applyHeuristic(int iParent1Index, int iParent2Index, int iChild1Index, int iChild2Index) {
		int i = this.random.nextInt(this.problem.getNumberOfVariables() - 2) + 1;
		this.problem.copySolution(iParent1Index, iChild1Index);
		this.problem.copySolution(iParent2Index, iChild2Index);
		
		for (iParent1Index = 0; iParent1Index < this.problem.getNumberOfVariables(); iParent1Index++) {
			if (iParent1Index < i) {
				this.problem.exchangeBits(iChild1Index, iChild2Index, iParent1Index);
			}
		}
	}
}
