#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar  1 23:19:44 2021

@author: qianzhang
"""

import sys
from collections import deque

from utils import *
#%matplotlib inline
import matplotlib.pyplot as plt
import random
import heapq
import math
import sys
from collections import defaultdict, deque, Counter
from itertools import combinations



# ______________________________________________________________________________
# Abstract class of problem and Node
# expand to generate successors; 
# path_actions and path_states to recover aspects of the path from the node.  

class Problem(object):
    """The abstract class for a formal problem. A new domain subclasses this,
    overriding `actions` and `results`, and perhaps other methods.
    The default heuristic is 0 and the default action cost is 1 for all states.
    When you create an instance of a subclass, specify `initial`, and `goal` states 
    (or give an `is_goal` method) and perhaps other keyword args for the subclass."""
    
    # **kwds Keywords arguments, a dictionary type 
    
    def __init__(self, initial=None, goal=None, **kwds):  #here self defining the problem itself
        self.__dict__.update(initial=initial, goal=goal, **kwds) 
        
    def actions(self, state):        raise NotImplementedError #return possible actions given state s, it regarded as sucessor functions in the slides
    def result(self, state, action): raise NotImplementedError # return result state given by start state and valid action
    def is_goal(self, state):        return state == self.goal
    def action_cost(self, s, a, s1): return 1 #travel from state s to s1 cost 1, s=>start state, a=>action, s1=>resulting state,
    def h(self, node):               return 0
    
    def __str__(self):
        return '{}({!r}, {!r})'.format(
            type(self).__name__, self.initial, self.goal) #define canonical representation of problem. Problemname(initial state, goal)   
    
class Node:
    "A Node in a search tree."
    def __init__(self, state, parent=None, action=None, path_cost=0): #here self defining the current node object
        self.__dict__.update(state=state, parent=parent, action=action, path_cost=path_cost)

    def __repr__(self): return '<{}>'.format(self.state) #print out format of node, <state name>
    def __len__(self): return 0 if self.parent is None else (1 + len(self.parent)) #depth of node
    def __lt__(self, other): return self.path_cost < other.path_cost #define the way of comparing two nodes.
    
    
failure = Node('failure', path_cost=math.inf) # Indicates an algorithm couldn't find a solution. state = 'failure'
cutoff  = Node('cutoff',  path_cost=math.inf) # Indicates iterative deepening search was cut off. state = 'cutoff'
    
    
def expand(problem, node):
    "Expand a node, generating the children nodes."
    s = node.state
    for action in problem.actions(s): #problem.actions(s) return all the possible actions on state s
        s1 = problem.result(s, action)
        cost = node.path_cost + problem.action_cost(s, action, s1)
        yield Node(s1, node, action, cost) #(yield)can be viewed as generator, expand node will yield several nodes (neighbours/frontier) reachable from the current node
        
def path_actions(node):
    "The sequence of actions to get to this node." #solution
    if node.parent is None:
        return []  
    return path_actions(node.parent) + [node.action] #list of actions from current node to root node

def path_states(node):
    "The sequence of states to get to this node."
    if node in (cutoff, failure, None): 
        return []
    return path_states(node.parent) + [node.state] #list of states from current node to root node


# ______________________________________________________________________________
# Queue implementation
# First-in-first-out and Last-in-first-out queues, and a `PriorityQueue`, which allows you to keep a collection of items, and continually remove from it the item with minimum `f(item)` score.

FIFOQueue = deque # check with help(deque), add to the right most, remove from the left most

LIFOQueue = list #add to the right most, remove the right most

class PriorityQueue: #used in best first search
    """A queue in which the item with minimum f(item) is always popped first."""

    def __init__(self, items=(), key=lambda x: x): 
        self.key = key
        self.items = [] # a heap of (score, item) pairs
        for item in items:
            self.add(item)
         
    def add(self, item):
        """Add item to the queuez."""
        pair = (self.key(item), item) #pair is a tuple type
        heapq.heappush(self.items, pair) #put the node to the sorted priority queue at the correct location w.r.t. value of key(item)

    def pop(self):
        """Pop and return the item with min f(item) value."""
        return heapq.heappop(self.items)[1]
    
    def top(self): return self.items[0][1]

    def __len__(self): return len(self.items)


# ______________________________________________________________________________
# Search Algorithms
# Best-first search with various f(n) functions gives us different search algorithms. 
# Note that A*, and greedy search can be given a heuristic function, h, but if h is not supplied they use the problem's default h function (if the problem does not define one, it is taken as h(n) = 0).
    
def breadth_first_tree_search(problem): #edit by qz
    "Search shallowest nodes in the search tree first."
    node = Node(problem.initial)
    frontier = FIFOQueue([node]) # queue
    while frontier: #frontier is not empty
        node = frontier.pop() #remove and return the right most element => front
        if problem.is_goal(node.state):
            return node
        for child in expand(problem, node):
            s = child.state
            frontier.appendleft(child) # add to the left most => tail
    return failure

def depth_first_tree_search(problem):#edit by qz
    "Search deepest nodes in the search tree first."
    node = Node(problem.initial)
    frontier = LIFOQueue([node])
    while frontier:
        node = frontier.pop() #remove the right most element
        if problem.is_goal(node.state):
            return node
        for child in expand(problem, node):
            s = child.state
            frontier.append(child)
    return failure

def depth_limited_tree_search(problem, limit=10): #edit by qz
    "Search deepest nodes in the search tree first."
    frontier = LIFOQueue([Node(problem.initial)])
    result = failure
    while frontier:
        node = frontier.pop()
        if problem.is_goal(node.state):
            return node
        elif len(node) >= limit:
            result = cutoff
        elif not is_cycle(node):
            for child in expand(problem, node):
                frontier.append(child)
    return result

def best_first_tree_search(problem, f):
    "A version of best_first_search without the `reached` table."
    frontier = PriorityQueue([Node(problem.initial)], key=f)
    while frontier:
        node = frontier.pop()
        if problem.is_goal(node.state):
            return node
        for child in expand(problem, node):
            if not is_cycle(child):
                frontier.add(child)
    return failure

def g(n): return n.path_cost    

def is_cycle(node, k=30):
    "Does this node form a cycle of length k or less?"
    def find_cycle(ancestor, k):
        return (ancestor is not None and k > 0 and
                (ancestor.state == node.state or find_cycle(ancestor.parent, k - 1)))
    return find_cycle(node.parent, k)

def uniform_cost_search(problem):
    "Search nodes with minimum path cost first."
    return best_first_tree_search(problem, f=g)

def astar_tree_search(problem, h=None):
    """Search nodes with minimum f(n) = g(n) + h(n), with no `reached` table."""
    h = h or problem.h # if h=None, h = problem.h, otherwise, h=h
    return best_first_tree_search(problem, f=lambda n: g(n) + h(n)) #n is input, g(n)+h(n) is returned value of lambda function f 

def breadth_first_bfs(problem):
    "Search shallowest nodes in the frontier search tree first; using best-first."
    #this is a best first tree search implementation 
    return best_first_tree_search(problem, f=len)

def depth_first_bfs(problem):
    #this is a best first tree search implementation 
    "Search deepest nodes in the frontier search tree first; using best-first."
    return best_first_tree_search(problem, f=lambda n: -len(n))


