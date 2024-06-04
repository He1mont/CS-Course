package com.aim.runners;

import com.aim.TestFrameConfig;

/**
 * Test frame/experimental configuration for lab exercise 2c (optional exercise).
 * 
 * @author Warren G. Jackson
 * @since 07/02/2024
 * @version 1.0.0
 *
 */
public class Exercise2cTestFrameConfig extends TestFrameConfig {

	/*
	 * You should perform some experiments adapting the list length to find a good performance.
	 * Q - What is this equivalent to if using a list length of 1?
	 */
	protected final int LIST_LENGTH = 5;

	private static final long m_parentSeed = 16022024L;

	/*
	 * permitted total runs = 11
	 */
	protected final int TRIALS_PER_TEST = 11;

	/*
	 * permitted instance ID's = 1
	 */
	protected final int INSTANCE_ID = 1;

	/*
	 * permitted run times (seconds) = 10
	 */
	protected final int RUN_TIME = 10;

	/**
	 *
	 */
	private static Exercise2cTestFrameConfig oThis;

	/**
	 *
	 */
	private Exercise2cTestFrameConfig() {

		super(new long[] {m_parentSeed});
	}

	/**
	 *
	 * @return The configuration instance.
	 */
	public synchronized static Exercise2cTestFrameConfig getInstance() {

		if (oThis == null) {
			oThis = new Exercise2cTestFrameConfig();
		}

		return oThis;
	}

	@Override
	public int getTotalRuns() {
		return this.TRIALS_PER_TEST;
	}

	@Override
	public int getInstanceId() {
		return this.INSTANCE_ID;
	}

	@Override
	public int getRunTime() {
		return this.RUN_TIME;
	}

	public int getListLength() { return LIST_LENGTH; }

	@Override
	public String getMethodName() {
		return "Late Acceptance";
	}

	@Override
	public String getConfigurationAsString() {
		return "L =  " + LIST_LENGTH;
	}

}
