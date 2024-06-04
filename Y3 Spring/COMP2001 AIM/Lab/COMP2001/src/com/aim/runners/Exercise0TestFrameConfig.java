package com.aim.runners;

import com.aim.TestFrameConfig;

/**
 * 
 * @author Warren G. Jackson
 *
 */
public class Exercise0TestFrameConfig extends TestFrameConfig {

	/**
	 * The experimental seed, set as the date of the in-person lab.
	 */
	private static final long[] m_seeds = { 02022024, 02022025, 02022026 };

	/*
	 * permitted instance ID's = 1
	 */
	private final int INSTANCE_ID = 1;

	/*
	 * permitted run times (nominal seconds) = 10
	 */
	private final int RUN_TIME = 10;

	/**
	 * Sets the number of trials equal to the number of experimental seeds.
	 */
	private final int TRIALS_PER_TEST = m_seeds.length;

	/**
	 * Singleton instance.
	 */
	private static Exercise0TestFrameConfig oThis;

	/**
	 * 
	 */
	private Exercise0TestFrameConfig() {

		super(m_seeds);
	}

	/**
	 * 
	 * @return The Singleton instantiation of this class.
	 */
	public static synchronized Exercise0TestFrameConfig getConfig() {

		if (oThis == null) {
			oThis = new Exercise0TestFrameConfig();
		}

		return oThis;
	}

	@Override
	public int getInstanceId() {
		return INSTANCE_ID;
	}

	@Override
	public int getRunTime() {
		return RUN_TIME;
	}

	@Override
	public String getMethodName() {
		return "Random Walk";
	}

	@Override
	public String getConfigurationAsString() {
		
		return String.format("SAT instance #%d with a run time of %d nominal seconds.", INSTANCE_ID, RUN_TIME);
	}

	@Override
	public int getTotalRuns() {
		return TRIALS_PER_TEST;
	}

}
