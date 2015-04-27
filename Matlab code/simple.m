classdef simple
   properties
       prout1
       prout2
   end
   methods
       function r = total(obj)
           r = obj.prout1 + obj.prout2;
       end
   end
end