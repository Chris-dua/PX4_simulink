function launchSimulinkPlant
%

%   Copyright 2021 The MathWorks, Inc.

    project = simulinkproject;
    projectRoot = project.RootFolder;
    open_system(fullfile(projectRoot,'models','px4CtrlQGCGPS.slx'));
end
