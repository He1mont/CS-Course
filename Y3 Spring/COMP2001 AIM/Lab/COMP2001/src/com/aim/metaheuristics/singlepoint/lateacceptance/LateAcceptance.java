package com.aim.metaheuristics.singlepoint.lateacceptance;

import com.aim.pseudorandom.RandomBitFlipHeuristic;
import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;
import uk.ac.nott.cs.aim.searchmethods.SinglePointSearchMethod;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class LateAcceptance extends SinglePointSearchMethod {
    int lengthLA;
    ArrayList<Double> history = new ArrayList<>();

    /**
     * Creates a search method with a population size of 2; one for the current solution,
     * and one for the backup solution. Creating a copy of the current the solution in the
     * backup solution index.
     *
     * @param problem The problem to be solved by the single point-based search method.
     * @param random  The random number generator.
     */
    public LateAcceptance(SAT problem, Random random, int length) {

        super(problem, random);
        lengthLA = length;
        for (int i = 0; i < length; i++) {
            history.add(Double.MAX_VALUE);
        }
    }

    @Override
    protected void runMainLoop() {
        new RandomBitFlipHeuristic(random).applyHeuristic(problem);
        double curr = problem.getObjectiveFunctionValue(CURRENT_SOLUTION_INDEX);
        double prev = problem.getObjectiveFunctionValue(BACKUP_SOLUTION_INDEX);

        if (curr < history.getFirst()) {
            history.addLast(curr);
            problem.copySolution(CURRENT_SOLUTION_INDEX, BACKUP_SOLUTION_INDEX);
        } else {
            history.addLast(prev);
            problem.copySolution(BACKUP_SOLUTION_INDEX, CURRENT_SOLUTION_INDEX);
        }
        history.removeFirst();
    }

    public String toString() {
    
        return "Late Acceptance";
	}
}
