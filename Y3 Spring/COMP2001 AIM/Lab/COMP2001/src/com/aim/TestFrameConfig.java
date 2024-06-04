package com.aim;

/**
 * 
 * @author Warren G. Jackson
 *
 */
public abstract class TestFrameConfig {

	private final long[] m_seeds;
	
	public TestFrameConfig(long[] seeds) {
		this.m_seeds = seeds;
	}
	
	public abstract int getInstanceId();
	
	public abstract int getRunTime();
	
	public abstract String getMethodName();
	
	public abstract String getConfigurationAsString();
	
	public abstract int getTotalRuns();
	
	public long[] getSeeds() {
		
		return m_seeds;
	}
	
	public String getBoxPlotTitle(int iTotalRuns) {
		
		String config = getConfigurationAsString();
		return "Results for " + getMethodName() + " given " + getRunTime() +
				" seconds for solving instance ID " + getInstanceId() + " over " +
				iTotalRuns + " runs" + (config == null ? "." : (" with " + config + "."));
	}
}
