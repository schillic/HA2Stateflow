clc
clear all
% figure
load('interval_flatten_virtual.mat');% virtual plant exp data with step size 1/50000 = 0.00002 ode 4 & time period same
% load('virtual_composed.mat');% exp data with step size 1/50000 = 0.00002 ode 4 & time period same
v_exp = interval_flatten_virtual.Y.Data; 
v = v_exp (217331:219293);
texp = interval_flatten_virtual.X.Data;
t = texp(217331:219293);
t1 = t-4.342670293215967; 
load('buck_interval_flatten_slsf.mat'); % stateflow data

load('interval_flatten_actualv2.mat');% exp data for actual plant with composed model
v_exp2 = interval_flatten_actualv2.Y.Data;
v2 = v_exp2(202205:204063);
t_exp2 = interval_flatten_actualv2.X.Data;
t2 = t_exp2(202205:204063);
t3 = t2-4.040213211428572;

%define handles%
p1 = plot_2d_vertices('output_t_vc_flatten.gen',[0.75 0.75 0.75]);% spaceex data 
p1 = p1(1);
hold on;
box on;
grid;%
p2 = plot(t1,v,'r','LineWidth',2.5);%exp data1
axis ([0 0.0375 0 19]);
p3 = plot(t3,v2,'g','LineWidth',1.5);%exp data2
p4 =  plot(ScopeData.signals(2).values, ScopeData.signals(3).values);%slsf data2

xlabel('Time, Sec','FontSize',20,'LineWidth',3);
ylabel('v_C, V','FontSize',20,'LineWidth',3);
legend([p1, p2, p3, p4],'SpaceEx','dSPACE - Virtual','dSPACE - Actual','Stateflow','Location','SouthEast')
set(gca,'FontSize',20,'LineWidth',3);
hold off

% print pdf
set(gcf, 'PaperUnits', 'inches');
x_width=5.4 ;y_width=4.0;% Figure size
set(gcf,'PaperSize',[5.1 3.85]);
set(gcf, 'PaperPosition', [0 0 x_width y_width]); % set position on paper
saveas(gcf,'buck_plot_interval_flatten.pdf')