"""
Class for maintaining explored sets
"""

class Explored(object):
    """
    Maintain an explored set.  Assumes that states are hashable
    (e.g. state is represented by a tuple)
    """
    

    def __init__(self):
        "__init__() - Create an empty explored set"

        self.exploredSet = {}
        

    def exists(self, state):
        """
        exists(state) - Has this state already been explored?

        :param state:  Hashable problem state
        :return: True if already seen, False otherwise4
        """
        seen = False
        if state in self.exploredSet.values():
            seen = True
        return seen


    def add(self, state):
        """
        add(state) - Add a given state to the explored set

        :param state:  A problem state that is hashable, e.g. a tuple
        :return: None
        """
        self.exploredSet[hash(state)] = state



