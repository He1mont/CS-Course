package com.aim;

import java.util.ArrayList;

/**
 * 
 * @author Warren G. Jackson
 *
 */
public class RunData {
		
	private final ArrayList<Double> m_data;
	
	private final Double m_best;
	
	private final String m_heuristicName;
	
	private final int m_heuristicId;
	
	private final int m_trialId;
	
	private final String m_solution;
	
	public RunData(ArrayList<Double> data, Double best, String heuristicName, int heuristicId, int trialId, String solution) {
		
		this.m_data = data;
		this.m_best = best;
		this.m_heuristicName = heuristicName;
		this.m_heuristicId = heuristicId;
		this.m_trialId = trialId;
		this.m_solution = solution;
	}
	
	public ArrayList<Double> getData() {
		return m_data;
	}
	
	public Double getBestSolutionValue() {
		return m_best;
	}
	
	public String getHeuristicName() {
		return m_heuristicName;
	}
	
	public int getHeuristicId() {
		return m_heuristicId;
	}
	
	public int getTrialId() {
		return m_trialId;
	}
	
	public String getBestSolutionSolutionAsString() {
		return m_solution;
	}
}
