package com.aim.metaheuristics.population.multimeme;

import java.util.Random;

import com.aim.metaheuristics.population.MemeplexInheritanceMethod;
import com.aim.metaheuristics.population.ParentSelection;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.Meme;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;

public class SimpleInheritanceMethod implements MemeplexInheritanceMethod {

	private final SAT problem;
	private final Random rng;
	
	public SimpleInheritanceMethod(SAT problem, Random rng) {
		
		this.problem = problem;
		this.rng = rng;
	}

	@Override
	public void performMemeticInheritance(int parent1, int parent2, int child1, int child2) {
		int parent;
		if (problem.getObjectiveFunctionValue(parent1) < problem.getObjectiveFunctionValue(parent2)) {
			parent = parent1;
		} else if (problem.getObjectiveFunctionValue(parent1) > problem.getObjectiveFunctionValue(parent2)) {
			parent = parent2;
		} else {
			// random selection
			if (rng.nextDouble() < 0.5) {
				parent = parent1;
			} else {
				parent = parent2;
			}
		}
		for (int i = 0; i < problem.getNumberOfMemes(); i++) {
			problem.getMeme(child1, i).setMemeOption(problem.getMeme(parent, i).getMemeOption());
			problem.getMeme(child2, i).setMemeOption(problem.getMeme(parent, i).getMemeOption());
		}
	}
}
