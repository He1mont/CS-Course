package com.aim.pseudorandom;

/**
 * 
 * @author Warren G. Jackson
 *
 */
public record Result(
		/**
		 * Name of the problem domain.
		 */
		String domain, 
		/**
		 * Instance ID.
		 */
		int instance, 
		/**
		 * Trial ID.
		 */
		int trialId, 
		/**
		 * Experimental seed.
		 */
		long seed, 
		/**
		 * Objective value of the best solution found.
		 */
		double f_best, 
		/**
		 * Actual CPU time taken.
		 */
		double cpuTimeTaken, 
		/**
		 * Nominal time taken (with respect to the CHeSC 2011 Competition computer).
		 */
		double nominalTimeTaken) {
}

