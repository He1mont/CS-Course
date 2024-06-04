package com.aim.metaheuristics.singlepoint.simulatedannealing;


import java.util.Random;

import com.aim.pseudorandom.RandomBitFlipHeuristic;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;
import uk.ac.nott.cs.aim.searchmethods.SinglePointSearchMethod;


public class SimulatedAnnealing extends SinglePointSearchMethod {
	private final CoolingSchedule oCoolingSchedule;
	
	public SimulatedAnnealing(CoolingSchedule schedule, SAT problem, Random random) {
		
		super(problem, random);
		
		this.oCoolingSchedule = schedule;
	}

	protected void runMainLoop() {
		new RandomBitFlipHeuristic(random).applyHeuristic(problem);
		double delta = problem.getObjectiveFunctionValue(CURRENT_SOLUTION_INDEX) - problem.getObjectiveFunctionValue(BACKUP_SOLUTION_INDEX);
		double rnd = random.nextDouble();

		if (delta < 0 || rnd < Math.exp(-delta / oCoolingSchedule.getCurrentTemperature())) {
			problem.copySolution(CURRENT_SOLUTION_INDEX, BACKUP_SOLUTION_INDEX);
		} else {
			problem.copySolution(BACKUP_SOLUTION_INDEX, CURRENT_SOLUTION_INDEX);
		}
		// updateBest is already handled by the framework
		oCoolingSchedule.advanceTemperature();
	}
		
	public String toString() {
		return "Simulated Annealing with " + oCoolingSchedule.toString();
	}
}
