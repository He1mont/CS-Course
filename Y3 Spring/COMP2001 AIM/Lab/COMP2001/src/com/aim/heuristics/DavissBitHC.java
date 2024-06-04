package com.aim.heuristics;

import uk.ac.nott.cs.aim.domains.chesc2014_SAT.SAT;
import uk.ac.nott.cs.aim.helperfunctions.ArrayMethods;
import uk.ac.nott.cs.aim.satheuristics.SATHeuristic;

import java.util.Random;
import java.util.stream.IntStream;

public class DavissBitHC extends SATHeuristic {

    public DavissBitHC(Random random) {
        super(random);
    }

    private int[] createRandomPermutation(int length) {
        int[] ls = IntStream.range(0, length).toArray();
        return ArrayMethods.shuffle(ls, random);
    }

    /**
     *
     * @param problem The problem to be solved.
     */
    public void applyHeuristic(SAT problem) {
        // generate a random solution
//        problem.createRandomSolution(CURRENT_SOLUTION_INDEX);
        double best = problem.getObjectiveFunctionValue(CURRENT_SOLUTION_INDEX);
        int[] perm = createRandomPermutation(problem.getNumberOfVariables());

        for (int i : perm) {
            problem.bitFlip(i, CURRENT_SOLUTION_INDEX);
            double tmp = problem.getObjectiveFunctionValue(CURRENT_SOLUTION_INDEX);

            if (tmp < best) {
                best = tmp;
            } else {
                problem.bitFlip(i, CURRENT_SOLUTION_INDEX);
            }
        }
    }

    @Override
    public String getHeuristicName() {

        return "DBHC";
    }
}
