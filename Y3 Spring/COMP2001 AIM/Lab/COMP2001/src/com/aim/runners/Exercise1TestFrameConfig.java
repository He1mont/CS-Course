package com.aim.runners;

import java.util.Random;

import com.aim.TestFrameConfig;

import com.aim.heuristics.*;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;

/**
 * Test frame/experimental configuration for lab exercise 1.
 * 
 * @author Warren G. Jackson
 * @since 31/01/2021
 * @version 1.0.0
 *
 */
public class Exercise1TestFrameConfig extends TestFrameConfig {

	private static final long m_parentSeed = 9022024L;	// The experimental seed, set as the date this lab was released.
	private final int INSTANCE_ID = 9; 		// permitted instance ID's = 1, 4
	private final int RUN_TIME = 10;			// permitted run times (seconds) = 1, 5, 10, 20
	private final int TRIALS_PER_TEST = 11;
	private static Exercise1TestFrameConfig oThis;

	private Exercise1TestFrameConfig() {
		super(new long[] {m_parentSeed});
	}

	public synchronized static Exercise1TestFrameConfig getInstance() {
		if (oThis == null) {
			oThis = new Exercise1TestFrameConfig();
		}
		return oThis;
	}

	@Override
	public int getInstanceId() {
		return this.INSTANCE_ID;
	}

	@Override
	public int getRunTime() {
		return this.RUN_TIME;
	}

	@Override
	public String getMethodName() {
		return "Davis's Bit Hill Climbing and Steepest Descent";
	}

	@Override
	public String getConfigurationAsString() {

		return String.format("SAT instance #%d with a run time of %d nominal seconds.", INSTANCE_ID, RUN_TIME);
	}

	@Override
	public int getTotalRuns() {

		return TRIALS_PER_TEST;
	}

	/**
	 * This method should not be changed but is intended for personal use if you
	 * wish to try with other heuristics of your own making.
	 * 
	 * @param heuristicID 0 for the first heuristic, or 1 for the second.
	 * @param random      The random number generator used by all SATHeuristic's
	 * @return The corresponding SAT heuristic
	 */
	public static SATHeuristic getSATHeuristic(int heuristicID, Random random) {

		SATHeuristic heuristic = null;

		switch (heuristicID) {
		case 0:
			heuristic = new DavissBitHC(random);
			break;
			case 1:
				heuristic = new SteepestDescentHC(random);
				break;
			case 2:
				heuristic = new KBitDavissHC(2, random);
				break;
			case 3:
				heuristic = new ShallowestDescentHC(random);
				break;
		default:
			System.err.println("Request for more than 4 heuristics at a time!");
			System.exit(0);
		}

		return heuristic;
	}
}
