package com.aim.runners;

import com.aim.HyFlexTestFrame;

public class Exercise4TestFrameConfig extends HyFlexTestFrame {
	
	/*
	 * permitted run time(s) = { 30s }
	 */
	protected final long RUN_TIME_IN_SECONDS = 30;
	
	/*
	 * permitted problem domain(s) = { SAT, TSP, BP }
	 */
	protected final String[] PROBLEM_DOMAINS = { "SAT", "TSP", "BP" };
	
	/*
	 * permitted instance ID's:
	 * 
	 * 		SAT = { 3, 11 }
	 *      TSP = { 0, 6 } 
	 * 		BP  = { 7, 11 }
	 */
	protected final int[][] INSTANCE_IDs = { { 3, 11 }, { 0, 6 }, { 7, 11 } };
	
	/*
	 * default default score = { 5 }.
	 */
	protected final int DEFAULT_SCORE = 5;
	
	/*
	 * default lower bound = { 1 }.
	 */
	protected final int LOWER_BOUND = 1;
	
	/*
	 * default upper bound = { 10 }.
	 */
	protected final int UPPER_BOUND = 10;
	
	@Override
	public String[] getDomains() {
		
		return this.PROBLEM_DOMAINS;
	}

	@Override
	public int[][] getInstanceIDs() {
		
		return this.INSTANCE_IDs;
	}

	@Override
	public long getRunTime() {
		
		return (MILLISECONDS_IN_TEN_MINUTES * RUN_TIME_IN_SECONDS) / 600;
	}

}
