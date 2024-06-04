package com.aim.heuristics;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.helperfunctions.ArrayMethods;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;

import java.util.Random;
import java.util.stream.IntStream;


public class KBitDavissHC extends SATHeuristic {

	private final int k;

	public KBitDavissHC(int k, Random random) {
		
		super(random);
		this.k = k;
	}

	/**
	  * This heuristic is similar to Davis's Bit Hill Climbing
	 *  with one key difference. Note that we now have a variable 'k'.
	 *  This 'k' is used to determine the number of bit flips to
	 *  perform at each iteration before checking whether the solution
	 *  was improved.
	 *
	 *  For each iteration 'i', the bits perm[i] to perm[i+k-1] should
	 *  be flipped. Be careful of the edge case!
	  */
	public void applyHeuristic(SAT problem) {

	}

	@Override
	public String getHeuristicName() {

		return "kBDHC";
	}


}
