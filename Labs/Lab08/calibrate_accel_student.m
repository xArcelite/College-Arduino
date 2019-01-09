% calibrate_accel_student.m
%
% Written by Adam Wickenheiser
%

clearvars;
close all;
delete(instrfindall);
clc;

dev_name = 'Arduino Mega 2560';		% device name
port_name = 'COM4';					% default port (you must set this manually
baud = 9600;

port_obj = serial(port_name,'BaudRate',baud);
fopen(port_obj);
fprintf('%s found on %s\n',dev_name,port_name);
n = 120;
i = 0;
% read one sample from serial port
while n>10
format_str = '%f, %f, %f, %f, %f'
data = fscanf(port_obj,format_str);
i = i+1;
n = n-1;
button_is_pressed(i) = data(5,:); 
if button_is_pressed(i) == 1
        x(i) = data(2,:);
        y(i) = data(3,:);
        z(i) = data(4,:);
end
        
end



    

% close the serial port (make sure this goes after you are done taking
% data)
fclose(port_obj);