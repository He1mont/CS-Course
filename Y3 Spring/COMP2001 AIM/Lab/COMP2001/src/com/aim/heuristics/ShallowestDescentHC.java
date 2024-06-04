package com.aim.heuristics;


import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;

import java.util.Random;


public class ShallowestDescentHC extends SATHeuristic {

	public ShallowestDescentHC(Random random) {
		
		super(random);
	}

	/**
	  * This heuristic is similar to Steepest Descent Hill Climbing
	  * but the difference here is that we want to flip the bit that
	  * results in the least improvement (note this does not include
	  * no improvement).
	  */
	public void applyHeuristic(SAT problem) {
		
	}

	public String getHeuristicName() {
		
		return "Shallowest Descent HC";
	}

}
