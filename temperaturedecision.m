% Calculate the temperature increase in a box due to a light bulb. 
clc
clear

% Length = 0.6 % in meters about 2 feet
% Width = 0.6 % meters
% Height = 0.6 % meters

% Dimensions of box
Length = 0.8 % in meters about 2 feet
Width = 0.8 % meters
Height = 0.8 % meters
% Volume = Length*Width*Height; % Cubic meters
% volume_liters = 1000 * Volume % 1000 liters to cubic meter
volume_liters = 18;

% standard air is 20 percent O2 and 80 percent N2
liters_O = .2*volume_liters; 
liters_N = .8*volume_liters;

% Density of elements in box
O_density = 1.429; % O2 grams per liter
N_density = 1.251; % N2 grams per liter

% find the number of grams of O2 and N2 in the box
grams_O = liters_O * O_density ;
grams_N = liters_N * N_density ;

% Specif Heat (C) at STP (assuming specific heat is linear. It is not but the curves
% are close to linear for the range of temps we are dealing with. A more
% accurate version would need to account for specific heat changing
% temperature changes.) 

C_nitrogen = 1.04; % joules per gram degree Celsius difference
C_oxygen = 0.919; % joules per gram degree Celsius difference

% Light Bulb Watts. Lets assume that the energy is applied evenly to all
% atoms. I.e 80 percent of the joules will go to the nitrogen each second.
% The second assumption is that the lightbulb instantly starts emitting
% energy and stops when needed. Realistically it will produce energy
% linearly since a standard light bulb uses a resisitor to produce the
% light and the heat is a by product of the light. Resistors are linear.
watts = 60 % joules output per second
joules_to_nitrogen = .8*watts; % assume one second
joules_to_oxygen = .2*watts; 

% The formula delta_T = q/mc where delta_T is the temperature change, q is
% the energy added in joules, m is the mass in grams, and c is the specific
% heat

temperature_increase_nitrogen_per_second = joules_to_nitrogen/(grams_N * C_nitrogen);
temperature_increase_oxygen_per_second = joules_to_oxygen/(grams_O * C_oxygen);

total_temp_change_per_second = temperature_increase_nitrogen_per_second *0.8 + temperature_increase_oxygen_per_second *0.2
total_temp_change_per_minute = total_temp_change_per_second * 60

% So we have found out that the temperature change depends greatly on the







