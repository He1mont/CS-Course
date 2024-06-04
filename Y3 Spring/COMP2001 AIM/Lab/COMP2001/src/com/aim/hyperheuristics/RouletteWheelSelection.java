package com.aim.hyperheuristics;

import java.util.*;
import java.util.stream.Collectors;

public class RouletteWheelSelection {

	public HeuristicPair[] m_aoHeuristicPairs;

	public LinkedHashMap<HeuristicPair, Integer> m_oHeuristicScores;

	public final int m_iUpperBound;

	public final int m_iLowerBound;

	public final int m_iDefaultScore;

	public final Random rng;

	/**
	 * Constructs a Roulette Wheel Selection method using a LinkedHashMap.
	 * 
	 * @param hs 			An array of heuristic IDs.
	 * @param default_score The default score to give each heuristic.
	 * @param lower_bound   The lower bound on the heuristic scores.
	 * @param upper_bound   The upper bound on the heuristic scores.
	 * @param rng           The random number generator.
	 */
	public RouletteWheelSelection(HeuristicPair[] hs, int default_score, int lower_bound, int upper_bound, Random rng) {

		this(new LinkedHashMap<HeuristicPair, Integer>(), hs, default_score, lower_bound, upper_bound, rng);
	}

	/**
	 * Constructs a Roulette Wheel Selection method using the supplied Map.
	 * 
	 * @param heuristic_scores An empty Map for mapping heuristic IDs to heuristic scores.
	 * @param hs               The set of heuristic IDs for the (mutation, local_search) operators.
	 * @param default_score    The default score to give each heuristic.
	 * @param lower_bound      The lower bound on the heuristic scores.
	 * @param upper_bound      The upper bound on the heuristic scores.
	 * @param rng              The random number generator.
	 */
	public RouletteWheelSelection(LinkedHashMap<HeuristicPair, Integer> heuristic_scores, HeuristicPair[] hs,
			int default_score, int lower_bound, int upper_bound, Random rng) {

		this.m_aoHeuristicPairs = hs;
		this.m_oHeuristicScores = heuristic_scores;
		this.m_iUpperBound = upper_bound;
		this.m_iLowerBound = lower_bound;
		this.m_iDefaultScore = default_score;
		this.rng = rng;

		// initialise scores to the default_score
		for (HeuristicPair h : hs) {
			
			this.m_oHeuristicScores.put(h, default_score);
		}
	}

	/**
	 * 
	 * @param h The HeuristicPair to get the score of.
	 * @return The score for the aforementioned heuristic. If the HeuristicScore
	 *         does not exist, then you must return 0.
	 */
	public int getScore(HeuristicPair h) {

		return m_oHeuristicScores.get(h);
	}

	/**
	 * Increments the score (by 1) of the specified heuristic whilst respecting the
	 * upper and lower bounds.
	 * 
	 * @param h The HeuristicPair whose score should be incremented.
	 */
	public void incrementScore(HeuristicPair h) {
		
		if (getScore(h) < m_iUpperBound)
			m_oHeuristicScores.put(h, getScore(h) + 1);
	}

	/**
	 * Decrements the score (by 1) of the specified heuristic respecting the upper
	 * and lower bounds.
	 * 
	 * @param h The HeuristicPair whose score should be decremented.
	 */
	public void decrementScore(HeuristicPair h) {

		if (getScore(h) > m_iLowerBound)
			m_oHeuristicScores.put(h, getScore(h) - 1);
	}

	/**
	 * 
	 * @return The sum of scores of all heuristics.
	 */
	public int getTotalScore() {

		int sum = 0;
		for (HeuristicPair h: m_aoHeuristicPairs) {
			sum += getScore(h);
		}
		return sum;
	}

	/**
	 * See exercise sheet for pseudocode!
	 * 
	 * @return A heuristic based on the RWS method.
	 */
	public HeuristicPair performRouletteWheelSelection() {
		
		int total = getTotalScore();
		int value = rng.nextInt(total);
		int cumulativeScore = 0;
		int index = 0;

		HeuristicPair ret = m_aoHeuristicPairs[index];
		while (cumulativeScore < value) {
			ret = m_aoHeuristicPairs[index];
			cumulativeScore += getScore(m_aoHeuristicPairs[index++]);
		}
		return ret;
	}

	/****************************************
	 * Utility methods useful for debugging
	 ****************************************/

	/**
	 * Prints the heuristic IDs into the console.
	 */
	public void printHeuristicIds() {

		String ids = "["
				+ m_oHeuristicScores.entrySet().stream().map(e -> e.getKey().toString()).collect(Collectors.joining(", "))
				+ "]";
		System.out.println("IDs    = " + ids);
	}

	/**
	 * Prints the heuristic scores into the console.
	 */
	public void printHeuristicScores() {

		String scores = "[" + m_oHeuristicScores.entrySet().stream().map(e -> e.getValue().toString())
				.collect(Collectors.joining(", ")) + "]";
		System.out.println("Scores = " + scores);
	}
}
