

from csp_lib.backtrack_util import (first_unassigned_variable, 
                                    unordered_domain_values,
                                    no_inference)

def backtracking_search(csp,
                        select_unassigned_variable=first_unassigned_variable,
                        order_domain_values=unordered_domain_values,
                        inference=no_inference):
   assignment = csp.infer_assignment()
   if len(assignment) == 81:
      return (assignment, csp.nassigns)
   var = select_unassigned_variable(assignment,csp)
   for x in order_domain_values(var,assignment,csp):
      if csp.nconflicts(var,x,assignment) == 0:
         csp.assign(var, x, assignment)
         remove = csp.suppose(var,x)
         inferences = inference(csp,var,x,assignment,remove)
         if inferences != False:
            # for y in csp.curr_domains[var]:
            #    if y != x:
            #       csp.prune(var,y)
            
            result = backtracking_search(csp,select_unassigned_variable,unordered_domain_values,inference)
            if result != None:
               return result
         csp.restore(remove)
         assignment.pop(var)
   return None


    
   # """backtracking_search
   # Given a constraint satisfaction problem (CSP),
   # a function handle for selecting variables, 
   # a function handle for selecting elements of a domain,
   # and a function handle for making inferences after assignment,
   # solve the CSP using backtrack search

   # Returns two outputs:
   #    dictionary of assignments or None if there is no solution
   #    Number of variable assignments made in backtrack search (not counting
   #    assignments made by inference)
   # """
    
    # See Figure 6.5 of your book for details
