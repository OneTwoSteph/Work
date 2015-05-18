% CONSTRAINTS Contains the constraints used for establishing the dynamics
% model of the robot (not finished).
%
% Stephanie Amati, April 2015

%% Clear
clear all
close all
clc

%% Variables
syms theta
syms L
syms R

%% Matrix 
A = [1, 0, L*cos(theta), -R*cos(theta), 0;...
     0, 1, L*sin(theta), -R*sin(theta), 0;...
     1, 0, -L*cos(theta), 0, -R*cos(theta);...
     0, 1, -L*sin(theta), 0, -R*sin(theta)]
 
%% Reduction 
Ap = rref(A)