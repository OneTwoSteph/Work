% SIMPLE Just to test how a class works.
%
% Stephanie Amati, April 2015

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