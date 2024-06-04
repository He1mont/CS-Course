package com.aim.runners;

import com.aim.TestFrameConfig;

/**
 * Test frame/experimental configuration for lab 2.
 * 
 * @author Warren G. Jackson
 * @since 05/02/2023
 * @version 1.0.1
 *
 */
public class Exercise2aTestFrameConfig extends TestFrameConfig {

	/**
	 * The experimental seed, set as the date this lab was released.
	 */
	private static final long m_parentSeed = 16022024L;
	
	/**
	 * permitted total runs = 11
	 */
	protected final int TOTAL_RUNS  = 11;
	
	/**
	 * permitted instance ID's = 1
	 */
	protected final int INSTANCE_ID = 1;
	
	/**
	 * permitted run times (seconds) = 10
	 */
	protected final int RUN_TIME = 10;
	
	/**
	 * permitted values = 0, 1, 2, 3
	 */
	protected final int depthOfSearch = 2;
	
	/**
	 * permitted values = 0, 1, 2, 3
	 */
	protected final int intensityOfMutation = 2;
	
	/**
	 * 
	 */
	private static Exercise2aTestFrameConfig oThis;

	/**
	 * 
	 */
	private Exercise2aTestFrameConfig() {

		super(new long[] {m_parentSeed});
	}

	/**
	 * 
	 * @return
	 */
	public synchronized static Exercise2aTestFrameConfig getInstance() {

		if (oThis == null) {
			oThis = new Exercise2aTestFrameConfig();
		}

		return oThis;
	}
	
	@Override
	public int getTotalRuns() {
		return this.TOTAL_RUNS;
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
		return "Iterated Local Search";
	}

	@Override
	public String getConfigurationAsString() {
		return "intensityOfMutation = " + intensityOfMutation + " and depthOfSearch = " + depthOfSearch;
	}
	
	public int getDepthOfSearch() {
		return this.depthOfSearch;
	}
	
	public int getIntensityOfMutation() {
		return this.intensityOfMutation;
	}

}
