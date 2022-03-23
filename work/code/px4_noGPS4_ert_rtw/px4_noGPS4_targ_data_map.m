    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (px4_noGPS4_P)
        ;%
            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% px4_noGPS4_P.DiscreteDerivative_ICPrevScaled
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS4_P.DiscreteDerivative2_ICPrevScale
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS4_P.DiscreteDerivative_ICPrevScal_k
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS4_P.DiscreteDerivative2_ICPrevSca_a
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS4_P.DiscreteDerivative_ICPrevScal_a
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS4_P.DiscreteDerivative2_ICPrevSca_o
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS4_P.DiscreteDerivative_ICPrevScal_f
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS4_P.DiscreteDerivative1_ICPrevScale
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS4_P.DiscreteDerivative_ICPrevScal_e
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% px4_noGPS4_P.DiscreteDerivative1_ICPrevSca_k
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS4_P.Out1_Y0
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS4_P.Constant_Value
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS4_P.Out1_Y0_k
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS4_P.Constant_Value_c
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 158;
            section.data(158)  = dumData; %prealloc

                    ;% px4_noGPS4_P.Constant2_Value
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS4_P.Constant3_Value
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS4_P.Constant4_Value
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS4_P.Constant2_Value_l
                    section.data(4).logicalSrcIdx = 17;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS4_P.Constant3_Value_b
                    section.data(5).logicalSrcIdx = 18;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS4_P.Constant4_Value_j
                    section.data(6).logicalSrcIdx = 19;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS4_P.Constant2_Value_a
                    section.data(7).logicalSrcIdx = 20;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS4_P.Constant3_Value_p
                    section.data(8).logicalSrcIdx = 21;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS4_P.Switch2_Threshold
                    section.data(9).logicalSrcIdx = 22;
                    section.data(9).dtTransOffset = 8;

                    ;% px4_noGPS4_P.Gain8_Gain
                    section.data(10).logicalSrcIdx = 23;
                    section.data(10).dtTransOffset = 9;

                    ;% px4_noGPS4_P.Constant_Value_f
                    section.data(11).logicalSrcIdx = 24;
                    section.data(11).dtTransOffset = 10;

                    ;% px4_noGPS4_P.Gain5_Gain
                    section.data(12).logicalSrcIdx = 25;
                    section.data(12).dtTransOffset = 11;

                    ;% px4_noGPS4_P.Gain6_Gain
                    section.data(13).logicalSrcIdx = 26;
                    section.data(13).dtTransOffset = 12;

                    ;% px4_noGPS4_P.Gain4_Gain
                    section.data(14).logicalSrcIdx = 27;
                    section.data(14).dtTransOffset = 13;

                    ;% px4_noGPS4_P.Gain3_Gain
                    section.data(15).logicalSrcIdx = 28;
                    section.data(15).dtTransOffset = 14;

                    ;% px4_noGPS4_P.Gain2_Gain
                    section.data(16).logicalSrcIdx = 29;
                    section.data(16).dtTransOffset = 15;

                    ;% px4_noGPS4_P.Saturation_UpperSat
                    section.data(17).logicalSrcIdx = 30;
                    section.data(17).dtTransOffset = 16;

                    ;% px4_noGPS4_P.Saturation_LowerSat
                    section.data(18).logicalSrcIdx = 31;
                    section.data(18).dtTransOffset = 17;

                    ;% px4_noGPS4_P.Constant_Value_d
                    section.data(19).logicalSrcIdx = 32;
                    section.data(19).dtTransOffset = 18;

                    ;% px4_noGPS4_P.Constant_Value_p
                    section.data(20).logicalSrcIdx = 33;
                    section.data(20).dtTransOffset = 19;

                    ;% px4_noGPS4_P.Constant2_Value_o
                    section.data(21).logicalSrcIdx = 34;
                    section.data(21).dtTransOffset = 20;

                    ;% px4_noGPS4_P.Constant1_Value
                    section.data(22).logicalSrcIdx = 35;
                    section.data(22).dtTransOffset = 21;

                    ;% px4_noGPS4_P.Constant_Value_j
                    section.data(23).logicalSrcIdx = 36;
                    section.data(23).dtTransOffset = 22;

                    ;% px4_noGPS4_P.Constant2_Value_e
                    section.data(24).logicalSrcIdx = 37;
                    section.data(24).dtTransOffset = 23;

                    ;% px4_noGPS4_P.Constant1_Value_d
                    section.data(25).logicalSrcIdx = 38;
                    section.data(25).dtTransOffset = 24;

                    ;% px4_noGPS4_P.Constant_Value_e
                    section.data(26).logicalSrcIdx = 39;
                    section.data(26).dtTransOffset = 25;

                    ;% px4_noGPS4_P.Constant_Value_b
                    section.data(27).logicalSrcIdx = 40;
                    section.data(27).dtTransOffset = 26;

                    ;% px4_noGPS4_P.DiscreteTimeIntegrator_gainval
                    section.data(28).logicalSrcIdx = 41;
                    section.data(28).dtTransOffset = 27;

                    ;% px4_noGPS4_P.DiscreteTimeIntegrator_IC
                    section.data(29).logicalSrcIdx = 42;
                    section.data(29).dtTransOffset = 28;

                    ;% px4_noGPS4_P.Constant9_Value
                    section.data(30).logicalSrcIdx = 43;
                    section.data(30).dtTransOffset = 29;

                    ;% px4_noGPS4_P.Constant5_Value
                    section.data(31).logicalSrcIdx = 44;
                    section.data(31).dtTransOffset = 30;

                    ;% px4_noGPS4_P.Constant7_Value
                    section.data(32).logicalSrcIdx = 45;
                    section.data(32).dtTransOffset = 31;

                    ;% px4_noGPS4_P.Constant8_Value
                    section.data(33).logicalSrcIdx = 46;
                    section.data(33).dtTransOffset = 32;

                    ;% px4_noGPS4_P.e_pitch_InitialValue
                    section.data(34).logicalSrcIdx = 47;
                    section.data(34).dtTransOffset = 33;

                    ;% px4_noGPS4_P.e_pitch1_InitialValue
                    section.data(35).logicalSrcIdx = 48;
                    section.data(35).dtTransOffset = 34;

                    ;% px4_noGPS4_P.e_pitch2_InitialValue
                    section.data(36).logicalSrcIdx = 49;
                    section.data(36).dtTransOffset = 35;

                    ;% px4_noGPS4_P.DataStoreMemory33_InitialValue
                    section.data(37).logicalSrcIdx = 50;
                    section.data(37).dtTransOffset = 36;

                    ;% px4_noGPS4_P.DataStoreMemory34_InitialValue
                    section.data(38).logicalSrcIdx = 51;
                    section.data(38).dtTransOffset = 37;

                    ;% px4_noGPS4_P.DataStoreMemory35_InitialValue
                    section.data(39).logicalSrcIdx = 52;
                    section.data(39).dtTransOffset = 38;

                    ;% px4_noGPS4_P.DataStoreMemory5_InitialValue
                    section.data(40).logicalSrcIdx = 53;
                    section.data(40).dtTransOffset = 39;

                    ;% px4_noGPS4_P.TSamp_WtEt
                    section.data(41).logicalSrcIdx = 54;
                    section.data(41).dtTransOffset = 40;

                    ;% px4_noGPS4_P.TSamp_WtEt_l
                    section.data(42).logicalSrcIdx = 55;
                    section.data(42).dtTransOffset = 41;

                    ;% px4_noGPS4_P.Gain3_Gain_m
                    section.data(43).logicalSrcIdx = 56;
                    section.data(43).dtTransOffset = 42;

                    ;% px4_noGPS4_P.TSamp_WtEt_m
                    section.data(44).logicalSrcIdx = 57;
                    section.data(44).dtTransOffset = 43;

                    ;% px4_noGPS4_P.Gain2_Gain_n
                    section.data(45).logicalSrcIdx = 58;
                    section.data(45).dtTransOffset = 44;

                    ;% px4_noGPS4_P.Gain4_Gain_i
                    section.data(46).logicalSrcIdx = 59;
                    section.data(46).dtTransOffset = 45;

                    ;% px4_noGPS4_P.Gain5_Gain_j
                    section.data(47).logicalSrcIdx = 60;
                    section.data(47).dtTransOffset = 46;

                    ;% px4_noGPS4_P.Gain6_Gain_b
                    section.data(48).logicalSrcIdx = 61;
                    section.data(48).dtTransOffset = 47;

                    ;% px4_noGPS4_P.Constant_Value_bt
                    section.data(49).logicalSrcIdx = 62;
                    section.data(49).dtTransOffset = 48;

                    ;% px4_noGPS4_P.TSamp_WtEt_j
                    section.data(50).logicalSrcIdx = 63;
                    section.data(50).dtTransOffset = 49;

                    ;% px4_noGPS4_P.Switch2_Threshold_m
                    section.data(51).logicalSrcIdx = 64;
                    section.data(51).dtTransOffset = 50;

                    ;% px4_noGPS4_P.Gain8_Gain_e
                    section.data(52).logicalSrcIdx = 65;
                    section.data(52).dtTransOffset = 51;

                    ;% px4_noGPS4_P.Gain3_Gain_f
                    section.data(53).logicalSrcIdx = 66;
                    section.data(53).dtTransOffset = 52;

                    ;% px4_noGPS4_P.TSamp_WtEt_h
                    section.data(54).logicalSrcIdx = 67;
                    section.data(54).dtTransOffset = 53;

                    ;% px4_noGPS4_P.Gain2_Gain_o
                    section.data(55).logicalSrcIdx = 68;
                    section.data(55).dtTransOffset = 54;

                    ;% px4_noGPS4_P.Gain4_Gain_g
                    section.data(56).logicalSrcIdx = 69;
                    section.data(56).dtTransOffset = 55;

                    ;% px4_noGPS4_P.Gain5_Gain_p
                    section.data(57).logicalSrcIdx = 70;
                    section.data(57).dtTransOffset = 56;

                    ;% px4_noGPS4_P.Gain6_Gain_a
                    section.data(58).logicalSrcIdx = 71;
                    section.data(58).dtTransOffset = 57;

                    ;% px4_noGPS4_P.Constant_Value_n
                    section.data(59).logicalSrcIdx = 72;
                    section.data(59).dtTransOffset = 58;

                    ;% px4_noGPS4_P.TSamp_WtEt_g
                    section.data(60).logicalSrcIdx = 73;
                    section.data(60).dtTransOffset = 59;

                    ;% px4_noGPS4_P.Switch2_Threshold_h
                    section.data(61).logicalSrcIdx = 74;
                    section.data(61).dtTransOffset = 60;

                    ;% px4_noGPS4_P.Gain8_Gain_p
                    section.data(62).logicalSrcIdx = 75;
                    section.data(62).dtTransOffset = 61;

                    ;% px4_noGPS4_P.Gain7_Gain
                    section.data(63).logicalSrcIdx = 76;
                    section.data(63).dtTransOffset = 62;

                    ;% px4_noGPS4_P.DataStoreMemory_InitialValue
                    section.data(64).logicalSrcIdx = 77;
                    section.data(64).dtTransOffset = 63;

                    ;% px4_noGPS4_P.Gain7_Gain_c
                    section.data(65).logicalSrcIdx = 78;
                    section.data(65).dtTransOffset = 64;

                    ;% px4_noGPS4_P.DataStoreMemory_InitialValue_f
                    section.data(66).logicalSrcIdx = 79;
                    section.data(66).dtTransOffset = 65;

                    ;% px4_noGPS4_P.Gain7_Gain_i
                    section.data(67).logicalSrcIdx = 80;
                    section.data(67).dtTransOffset = 66;

                    ;% px4_noGPS4_P.DataStoreMemory_InitialValue_l
                    section.data(68).logicalSrcIdx = 81;
                    section.data(68).dtTransOffset = 67;

                    ;% px4_noGPS4_P.Intgrt_dX_gainval
                    section.data(69).logicalSrcIdx = 82;
                    section.data(69).dtTransOffset = 68;

                    ;% px4_noGPS4_P.Intgrt_dX_IC
                    section.data(70).logicalSrcIdx = 83;
                    section.data(70).dtTransOffset = 69;

                    ;% px4_noGPS4_P.Intgrt_dY_gainval
                    section.data(71).logicalSrcIdx = 84;
                    section.data(71).dtTransOffset = 70;

                    ;% px4_noGPS4_P.Intgrt_dY_IC
                    section.data(72).logicalSrcIdx = 85;
                    section.data(72).dtTransOffset = 71;

                    ;% px4_noGPS4_P.Intgrt_ddY_gainval
                    section.data(73).logicalSrcIdx = 86;
                    section.data(73).dtTransOffset = 72;

                    ;% px4_noGPS4_P.Intgrt_ddY_IC
                    section.data(74).logicalSrcIdx = 87;
                    section.data(74).dtTransOffset = 73;

                    ;% px4_noGPS4_P.Intgrt_ddX_gainval
                    section.data(75).logicalSrcIdx = 88;
                    section.data(75).dtTransOffset = 74;

                    ;% px4_noGPS4_P.Intgrt_ddX_IC
                    section.data(76).logicalSrcIdx = 89;
                    section.data(76).dtTransOffset = 75;

                    ;% px4_noGPS4_P.Constant6_Value
                    section.data(77).logicalSrcIdx = 90;
                    section.data(77).dtTransOffset = 76;

                    ;% px4_noGPS4_P.K1_Gain
                    section.data(78).logicalSrcIdx = 91;
                    section.data(78).dtTransOffset = 77;

                    ;% px4_noGPS4_P.TSamp_WtEt_c
                    section.data(79).logicalSrcIdx = 92;
                    section.data(79).dtTransOffset = 78;

                    ;% px4_noGPS4_P.C1_Gain
                    section.data(80).logicalSrcIdx = 93;
                    section.data(80).dtTransOffset = 79;

                    ;% px4_noGPS4_P.C3_Gain
                    section.data(81).logicalSrcIdx = 94;
                    section.data(81).dtTransOffset = 80;

                    ;% px4_noGPS4_P.C4_Gain
                    section.data(82).logicalSrcIdx = 95;
                    section.data(82).dtTransOffset = 81;

                    ;% px4_noGPS4_P.Switch1_Threshold
                    section.data(83).logicalSrcIdx = 96;
                    section.data(83).dtTransOffset = 82;

                    ;% px4_noGPS4_P.Gain_Gain
                    section.data(84).logicalSrcIdx = 97;
                    section.data(84).dtTransOffset = 83;

                    ;% px4_noGPS4_P.k3_Gain
                    section.data(85).logicalSrcIdx = 98;
                    section.data(85).dtTransOffset = 84;

                    ;% px4_noGPS4_P.Constant3_Value_h
                    section.data(86).logicalSrcIdx = 99;
                    section.data(86).dtTransOffset = 85;

                    ;% px4_noGPS4_P.TSamp_WtEt_l2
                    section.data(87).logicalSrcIdx = 100;
                    section.data(87).dtTransOffset = 86;

                    ;% px4_noGPS4_P.Gain2_Gain_oq
                    section.data(88).logicalSrcIdx = 101;
                    section.data(88).dtTransOffset = 87;

                    ;% px4_noGPS4_P.Saturation1_UpperSat
                    section.data(89).logicalSrcIdx = 102;
                    section.data(89).dtTransOffset = 88;

                    ;% px4_noGPS4_P.Saturation1_LowerSat
                    section.data(90).logicalSrcIdx = 103;
                    section.data(90).dtTransOffset = 89;

                    ;% px4_noGPS4_P.Constant_Value_i
                    section.data(91).logicalSrcIdx = 104;
                    section.data(91).dtTransOffset = 90;

                    ;% px4_noGPS4_P.k2_Gain
                    section.data(92).logicalSrcIdx = 105;
                    section.data(92).dtTransOffset = 91;

                    ;% px4_noGPS4_P.TSamp_WtEt_p
                    section.data(93).logicalSrcIdx = 106;
                    section.data(93).dtTransOffset = 92;

                    ;% px4_noGPS4_P.C1_Gain_j
                    section.data(94).logicalSrcIdx = 107;
                    section.data(94).dtTransOffset = 93;

                    ;% px4_noGPS4_P.k1_Gain
                    section.data(95).logicalSrcIdx = 108;
                    section.data(95).dtTransOffset = 94;

                    ;% px4_noGPS4_P.C2_Gain
                    section.data(96).logicalSrcIdx = 109;
                    section.data(96).dtTransOffset = 95;

                    ;% px4_noGPS4_P.Switch1_Threshold_k
                    section.data(97).logicalSrcIdx = 110;
                    section.data(97).dtTransOffset = 96;

                    ;% px4_noGPS4_P.Gain_Gain_a
                    section.data(98).logicalSrcIdx = 111;
                    section.data(98).dtTransOffset = 97;

                    ;% px4_noGPS4_P.k3_Gain_f
                    section.data(99).logicalSrcIdx = 112;
                    section.data(99).dtTransOffset = 98;

                    ;% px4_noGPS4_P.Constant3_Value_f
                    section.data(100).logicalSrcIdx = 113;
                    section.data(100).dtTransOffset = 99;

                    ;% px4_noGPS4_P.TSamp_WtEt_i
                    section.data(101).logicalSrcIdx = 114;
                    section.data(101).dtTransOffset = 100;

                    ;% px4_noGPS4_P.Gain4_Gain_c
                    section.data(102).logicalSrcIdx = 115;
                    section.data(102).dtTransOffset = 101;

                    ;% px4_noGPS4_P.Saturation2_UpperSat
                    section.data(103).logicalSrcIdx = 116;
                    section.data(103).dtTransOffset = 102;

                    ;% px4_noGPS4_P.Saturation2_LowerSat
                    section.data(104).logicalSrcIdx = 117;
                    section.data(104).dtTransOffset = 103;

                    ;% px4_noGPS4_P.Saturation2_UpperSat_b
                    section.data(105).logicalSrcIdx = 118;
                    section.data(105).dtTransOffset = 104;

                    ;% px4_noGPS4_P.Saturation2_LowerSat_m
                    section.data(106).logicalSrcIdx = 119;
                    section.data(106).dtTransOffset = 105;

                    ;% px4_noGPS4_P.fault_1_Value
                    section.data(107).logicalSrcIdx = 120;
                    section.data(107).dtTransOffset = 106;

                    ;% px4_noGPS4_P.Mixermatrix1_Value
                    section.data(108).logicalSrcIdx = 121;
                    section.data(108).dtTransOffset = 107;

                    ;% px4_noGPS4_P.Gain4_Gain_f
                    section.data(109).logicalSrcIdx = 122;
                    section.data(109).dtTransOffset = 123;

                    ;% px4_noGPS4_P.fault_2_Value
                    section.data(110).logicalSrcIdx = 123;
                    section.data(110).dtTransOffset = 124;

                    ;% px4_noGPS4_P.fault_3_Value
                    section.data(111).logicalSrcIdx = 124;
                    section.data(111).dtTransOffset = 125;

                    ;% px4_noGPS4_P.fault_4_Value
                    section.data(112).logicalSrcIdx = 125;
                    section.data(112).dtTransOffset = 126;

                    ;% px4_noGPS4_P.Intgrt_dZ_gainval
                    section.data(113).logicalSrcIdx = 126;
                    section.data(113).dtTransOffset = 127;

                    ;% px4_noGPS4_P.Intgrt_dZ_IC
                    section.data(114).logicalSrcIdx = 127;
                    section.data(114).dtTransOffset = 128;

                    ;% px4_noGPS4_P.Intgrt_ddZ_gainval
                    section.data(115).logicalSrcIdx = 128;
                    section.data(115).dtTransOffset = 129;

                    ;% px4_noGPS4_P.Intgrt_ddZ_IC
                    section.data(116).logicalSrcIdx = 129;
                    section.data(116).dtTransOffset = 130;

                    ;% px4_noGPS4_P.Saturation1_UpperSat_k
                    section.data(117).logicalSrcIdx = 130;
                    section.data(117).dtTransOffset = 131;

                    ;% px4_noGPS4_P.Saturation1_LowerSat_c
                    section.data(118).logicalSrcIdx = 131;
                    section.data(118).dtTransOffset = 132;

                    ;% px4_noGPS4_P.slower3_Gain
                    section.data(119).logicalSrcIdx = 132;
                    section.data(119).dtTransOffset = 133;

                    ;% px4_noGPS4_P.slower4_Gain
                    section.data(120).logicalSrcIdx = 133;
                    section.data(120).dtTransOffset = 134;

                    ;% px4_noGPS4_P.slower5_Gain
                    section.data(121).logicalSrcIdx = 134;
                    section.data(121).dtTransOffset = 135;

                    ;% px4_noGPS4_P.Gain5_Gain_g
                    section.data(122).logicalSrcIdx = 135;
                    section.data(122).dtTransOffset = 136;

                    ;% px4_noGPS4_P.Gain3_Gain_c
                    section.data(123).logicalSrcIdx = 136;
                    section.data(123).dtTransOffset = 137;

                    ;% px4_noGPS4_P.Gain6_Gain_k
                    section.data(124).logicalSrcIdx = 137;
                    section.data(124).dtTransOffset = 138;

                    ;% px4_noGPS4_P.Gain8_Gain_o
                    section.data(125).logicalSrcIdx = 138;
                    section.data(125).dtTransOffset = 139;

                    ;% px4_noGPS4_P.Gain10_Gain
                    section.data(126).logicalSrcIdx = 139;
                    section.data(126).dtTransOffset = 140;

                    ;% px4_noGPS4_P.Gain7_Gain_a
                    section.data(127).logicalSrcIdx = 140;
                    section.data(127).dtTransOffset = 141;

                    ;% px4_noGPS4_P.Gain11_Gain
                    section.data(128).logicalSrcIdx = 141;
                    section.data(128).dtTransOffset = 142;

                    ;% px4_noGPS4_P.Gain9_Gain
                    section.data(129).logicalSrcIdx = 142;
                    section.data(129).dtTransOffset = 143;

                    ;% px4_noGPS4_P.DataStoreMemory10_InitialValue
                    section.data(130).logicalSrcIdx = 143;
                    section.data(130).dtTransOffset = 144;

                    ;% px4_noGPS4_P.DataStoreMemory11_InitialValue
                    section.data(131).logicalSrcIdx = 144;
                    section.data(131).dtTransOffset = 145;

                    ;% px4_noGPS4_P.DataStoreMemory12_InitialValue
                    section.data(132).logicalSrcIdx = 145;
                    section.data(132).dtTransOffset = 146;

                    ;% px4_noGPS4_P.DataStoreMemory13_InitialValue
                    section.data(133).logicalSrcIdx = 146;
                    section.data(133).dtTransOffset = 147;

                    ;% px4_noGPS4_P.DataStoreMemory14_InitialValue
                    section.data(134).logicalSrcIdx = 147;
                    section.data(134).dtTransOffset = 148;

                    ;% px4_noGPS4_P.DataStoreMemory15_InitialValue
                    section.data(135).logicalSrcIdx = 148;
                    section.data(135).dtTransOffset = 149;

                    ;% px4_noGPS4_P.DataStoreMemory16_InitialValue
                    section.data(136).logicalSrcIdx = 149;
                    section.data(136).dtTransOffset = 150;

                    ;% px4_noGPS4_P.DataStoreMemory17_InitialValue
                    section.data(137).logicalSrcIdx = 150;
                    section.data(137).dtTransOffset = 151;

                    ;% px4_noGPS4_P.DataStoreMemory18_InitialValue
                    section.data(138).logicalSrcIdx = 151;
                    section.data(138).dtTransOffset = 152;

                    ;% px4_noGPS4_P.DataStoreMemory19_InitialValue
                    section.data(139).logicalSrcIdx = 152;
                    section.data(139).dtTransOffset = 153;

                    ;% px4_noGPS4_P.DataStoreMemory2_InitialValue
                    section.data(140).logicalSrcIdx = 153;
                    section.data(140).dtTransOffset = 154;

                    ;% px4_noGPS4_P.DataStoreMemory20_InitialValue
                    section.data(141).logicalSrcIdx = 154;
                    section.data(141).dtTransOffset = 155;

                    ;% px4_noGPS4_P.DataStoreMemory21_InitialValue
                    section.data(142).logicalSrcIdx = 155;
                    section.data(142).dtTransOffset = 156;

                    ;% px4_noGPS4_P.DataStoreMemory22_InitialValue
                    section.data(143).logicalSrcIdx = 156;
                    section.data(143).dtTransOffset = 157;

                    ;% px4_noGPS4_P.DataStoreMemory23_InitialValue
                    section.data(144).logicalSrcIdx = 157;
                    section.data(144).dtTransOffset = 158;

                    ;% px4_noGPS4_P.DataStoreMemory24_InitialValue
                    section.data(145).logicalSrcIdx = 158;
                    section.data(145).dtTransOffset = 159;

                    ;% px4_noGPS4_P.DataStoreMemory25_InitialValue
                    section.data(146).logicalSrcIdx = 159;
                    section.data(146).dtTransOffset = 160;

                    ;% px4_noGPS4_P.DataStoreMemory26_InitialValue
                    section.data(147).logicalSrcIdx = 160;
                    section.data(147).dtTransOffset = 161;

                    ;% px4_noGPS4_P.DataStoreMemory28_InitialValue
                    section.data(148).logicalSrcIdx = 161;
                    section.data(148).dtTransOffset = 162;

                    ;% px4_noGPS4_P.DataStoreMemory29_InitialValue
                    section.data(149).logicalSrcIdx = 162;
                    section.data(149).dtTransOffset = 163;

                    ;% px4_noGPS4_P.DataStoreMemory3_InitialValue
                    section.data(150).logicalSrcIdx = 163;
                    section.data(150).dtTransOffset = 164;

                    ;% px4_noGPS4_P.DataStoreMemory31_InitialValue
                    section.data(151).logicalSrcIdx = 164;
                    section.data(151).dtTransOffset = 165;

                    ;% px4_noGPS4_P.DataStoreMemory32_InitialValue
                    section.data(152).logicalSrcIdx = 165;
                    section.data(152).dtTransOffset = 166;

                    ;% px4_noGPS4_P.DataStoreMemory36_InitialValue
                    section.data(153).logicalSrcIdx = 166;
                    section.data(153).dtTransOffset = 167;

                    ;% px4_noGPS4_P.DataStoreMemory4_InitialValue
                    section.data(154).logicalSrcIdx = 167;
                    section.data(154).dtTransOffset = 168;

                    ;% px4_noGPS4_P.DataStoreMemory6_InitialValue
                    section.data(155).logicalSrcIdx = 168;
                    section.data(155).dtTransOffset = 169;

                    ;% px4_noGPS4_P.DataStoreMemory7_InitialValue
                    section.data(156).logicalSrcIdx = 169;
                    section.data(156).dtTransOffset = 170;

                    ;% px4_noGPS4_P.DataStoreMemory8_InitialValue
                    section.data(157).logicalSrcIdx = 170;
                    section.data(157).dtTransOffset = 171;

                    ;% px4_noGPS4_P.DataStoreMemory9_InitialValue
                    section.data(158).logicalSrcIdx = 171;
                    section.data(158).dtTransOffset = 172;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% px4_noGPS4_P.Reset_Value
                    section.data(1).logicalSrcIdx = 172;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS4_P.attitude_flag_Value
                    section.data(2).logicalSrcIdx = 173;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS4_P.observer_flag_Value
                    section.data(3).logicalSrcIdx = 174;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS4_P.position_flag_Value
                    section.data(4).logicalSrcIdx = 175;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS4_P.Constant2_Value_k
                    section.data(5).logicalSrcIdx = 176;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS4_P.DataStoreMemory_InitialValue_b
                    section.data(6).logicalSrcIdx = 177;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS4_P.DataStoreMemory1_InitialValue
                    section.data(7).logicalSrcIdx = 178;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS4_P.DataStoreMemory27_InitialValue
                    section.data(8).logicalSrcIdx = 179;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS4_P.DataStoreMemory30_InitialValue
                    section.data(9).logicalSrcIdx = 180;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS4_P.ManualSwitch_CurrentSetting
                    section.data(1).logicalSrcIdx = 181;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (px4_noGPS4_B)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS4_B.In1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS4_B.In1_a
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 35;
            section.data(35)  = dumData; %prealloc

                    ;% px4_noGPS4_B.DataStore
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS4_B.Gain5
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS4_B.Gain3
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS4_B.DataStoreRead13
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS4_B.DataStoreRead15
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS4_B.DataStoreRead16
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS4_B.DataStoreRead17
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS4_B.DataStoreRead19
                    section.data(8).logicalSrcIdx = 9;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS4_B.Gain6
                    section.data(9).logicalSrcIdx = 10;
                    section.data(9).dtTransOffset = 8;

                    ;% px4_noGPS4_B.DataStoreRead25
                    section.data(10).logicalSrcIdx = 11;
                    section.data(10).dtTransOffset = 9;

                    ;% px4_noGPS4_B.DataStoreRead26
                    section.data(11).logicalSrcIdx = 12;
                    section.data(11).dtTransOffset = 10;

                    ;% px4_noGPS4_B.DataStoreRead27
                    section.data(12).logicalSrcIdx = 13;
                    section.data(12).dtTransOffset = 11;

                    ;% px4_noGPS4_B.pitch_thrust
                    section.data(13).logicalSrcIdx = 14;
                    section.data(13).dtTransOffset = 12;

                    ;% px4_noGPS4_B.roll_thrust
                    section.data(14).logicalSrcIdx = 15;
                    section.data(14).dtTransOffset = 13;

                    ;% px4_noGPS4_B.yaw_thrust
                    section.data(15).logicalSrcIdx = 16;
                    section.data(15).dtTransOffset = 14;

                    ;% px4_noGPS4_B.tau_thrust
                    section.data(16).logicalSrcIdx = 17;
                    section.data(16).dtTransOffset = 15;

                    ;% px4_noGPS4_B.pitch
                    section.data(17).logicalSrcIdx = 18;
                    section.data(17).dtTransOffset = 16;

                    ;% px4_noGPS4_B.pitch_desire
                    section.data(18).logicalSrcIdx = 19;
                    section.data(18).dtTransOffset = 17;

                    ;% px4_noGPS4_B.roll
                    section.data(19).logicalSrcIdx = 20;
                    section.data(19).dtTransOffset = 18;

                    ;% px4_noGPS4_B.roll_desire
                    section.data(20).logicalSrcIdx = 21;
                    section.data(20).dtTransOffset = 19;

                    ;% px4_noGPS4_B.yaw
                    section.data(21).logicalSrcIdx = 22;
                    section.data(21).dtTransOffset = 20;

                    ;% px4_noGPS4_B.DataStoreRead34
                    section.data(22).logicalSrcIdx = 23;
                    section.data(22).dtTransOffset = 21;

                    ;% px4_noGPS4_B.DataStoreRead35
                    section.data(23).logicalSrcIdx = 24;
                    section.data(23).dtTransOffset = 22;

                    ;% px4_noGPS4_B.DataStoreRead36
                    section.data(24).logicalSrcIdx = 25;
                    section.data(24).dtTransOffset = 23;

                    ;% px4_noGPS4_B.DataStoreRead37
                    section.data(25).logicalSrcIdx = 26;
                    section.data(25).dtTransOffset = 24;

                    ;% px4_noGPS4_B.DataStoreRead38
                    section.data(26).logicalSrcIdx = 27;
                    section.data(26).dtTransOffset = 25;

                    ;% px4_noGPS4_B.DataStoreRead39
                    section.data(27).logicalSrcIdx = 28;
                    section.data(27).dtTransOffset = 26;

                    ;% px4_noGPS4_B.DataStoreRead42
                    section.data(28).logicalSrcIdx = 29;
                    section.data(28).dtTransOffset = 27;

                    ;% px4_noGPS4_B.DataStoreRead43
                    section.data(29).logicalSrcIdx = 30;
                    section.data(29).dtTransOffset = 28;

                    ;% px4_noGPS4_B.DataStoreRead44
                    section.data(30).logicalSrcIdx = 31;
                    section.data(30).dtTransOffset = 29;

                    ;% px4_noGPS4_B.DataStoreRead48
                    section.data(31).logicalSrcIdx = 32;
                    section.data(31).dtTransOffset = 30;

                    ;% px4_noGPS4_B.DataStoreRead49
                    section.data(32).logicalSrcIdx = 33;
                    section.data(32).dtTransOffset = 31;

                    ;% px4_noGPS4_B.DataStoreRead55
                    section.data(33).logicalSrcIdx = 34;
                    section.data(33).dtTransOffset = 32;

                    ;% px4_noGPS4_B.DataStoreRead8
                    section.data(34).logicalSrcIdx = 35;
                    section.data(34).dtTransOffset = 33;

                    ;% px4_noGPS4_B.DataStoreRead9
                    section.data(35).logicalSrcIdx = 36;
                    section.data(35).dtTransOffset = 34;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS4_B.output
                    section.data(1).logicalSrcIdx = 37;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% px4_noGPS4_B.NOT
                    section.data(1).logicalSrcIdx = 38;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS4_B.DataStoreRead12
                    section.data(2).logicalSrcIdx = 39;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 5;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (px4_noGPS4_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS4_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% px4_noGPS4_DW.obj_n
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS4_DW.obj_l
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 39;
            section.data(39)  = dumData; %prealloc

                    ;% px4_noGPS4_DW.UD_DSTATE
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS4_DW.UD_DSTATE_f
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS4_DW.UD_DSTATE_j
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS4_DW.UD_DSTATE_l
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS4_DW.UD_DSTATE_m
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS4_DW.UD_DSTATE_n
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS4_DW.Intgrt_dX_DSTATE
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS4_DW.Intgrt_dY_DSTATE
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS4_DW.Intgrt_ddY_DSTATE
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

                    ;% px4_noGPS4_DW.Intgrt_ddX_DSTATE
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 9;

                    ;% px4_noGPS4_DW.UD_DSTATE_g
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 10;

                    ;% px4_noGPS4_DW.UD_DSTATE_c
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 11;

                    ;% px4_noGPS4_DW.UD_DSTATE_n3
                    section.data(13).logicalSrcIdx = 15;
                    section.data(13).dtTransOffset = 12;

                    ;% px4_noGPS4_DW.UD_DSTATE_nw
                    section.data(14).logicalSrcIdx = 16;
                    section.data(14).dtTransOffset = 13;

                    ;% px4_noGPS4_DW.Intgrt_dZ_DSTATE
                    section.data(15).logicalSrcIdx = 17;
                    section.data(15).dtTransOffset = 14;

                    ;% px4_noGPS4_DW.Intgrt_ddZ_DSTATE
                    section.data(16).logicalSrcIdx = 18;
                    section.data(16).dtTransOffset = 15;

                    ;% px4_noGPS4_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(17).logicalSrcIdx = 19;
                    section.data(17).dtTransOffset = 16;

                    ;% px4_noGPS4_DW.s6_yaw
                    section.data(18).logicalSrcIdx = 27;
                    section.data(18).dtTransOffset = 17;

                    ;% px4_noGPS4_DW.s4_pitch
                    section.data(19).logicalSrcIdx = 28;
                    section.data(19).dtTransOffset = 18;

                    ;% px4_noGPS4_DW.s5_roll
                    section.data(20).logicalSrcIdx = 29;
                    section.data(20).dtTransOffset = 19;

                    ;% px4_noGPS4_DW.yaw_speed
                    section.data(21).logicalSrcIdx = 36;
                    section.data(21).dtTransOffset = 20;

                    ;% px4_noGPS4_DW.roll_speed
                    section.data(22).logicalSrcIdx = 37;
                    section.data(22).dtTransOffset = 21;

                    ;% px4_noGPS4_DW.pitch_speed
                    section.data(23).logicalSrcIdx = 38;
                    section.data(23).dtTransOffset = 22;

                    ;% px4_noGPS4_DW.pitch_acc
                    section.data(24).logicalSrcIdx = 39;
                    section.data(24).dtTransOffset = 23;

                    ;% px4_noGPS4_DW.roll_acc
                    section.data(25).logicalSrcIdx = 41;
                    section.data(25).dtTransOffset = 24;

                    ;% px4_noGPS4_DW.yaw_acc
                    section.data(26).logicalSrcIdx = 42;
                    section.data(26).dtTransOffset = 25;

                    ;% px4_noGPS4_DW.roll_desire
                    section.data(27).logicalSrcIdx = 43;
                    section.data(27).dtTransOffset = 26;

                    ;% px4_noGPS4_DW.pitch_desire
                    section.data(28).logicalSrcIdx = 44;
                    section.data(28).dtTransOffset = 27;

                    ;% px4_noGPS4_DW.q_x
                    section.data(29).logicalSrcIdx = 45;
                    section.data(29).dtTransOffset = 28;

                    ;% px4_noGPS4_DW.q_y
                    section.data(30).logicalSrcIdx = 46;
                    section.data(30).dtTransOffset = 29;

                    ;% px4_noGPS4_DW.q_z
                    section.data(31).logicalSrcIdx = 47;
                    section.data(31).dtTransOffset = 30;

                    ;% px4_noGPS4_DW.lat
                    section.data(32).logicalSrcIdx = 48;
                    section.data(32).dtTransOffset = 31;

                    ;% px4_noGPS4_DW.t
                    section.data(33).logicalSrcIdx = 49;
                    section.data(33).dtTransOffset = 32;

                    ;% px4_noGPS4_DW.lon
                    section.data(34).logicalSrcIdx = 51;
                    section.data(34).dtTransOffset = 33;

                    ;% px4_noGPS4_DW.alt
                    section.data(35).logicalSrcIdx = 52;
                    section.data(35).dtTransOffset = 34;

                    ;% px4_noGPS4_DW.U1
                    section.data(36).logicalSrcIdx = 53;
                    section.data(36).dtTransOffset = 35;

                    ;% px4_noGPS4_DW.pitch
                    section.data(37).logicalSrcIdx = 54;
                    section.data(37).dtTransOffset = 36;

                    ;% px4_noGPS4_DW.roll
                    section.data(38).logicalSrcIdx = 55;
                    section.data(38).dtTransOffset = 37;

                    ;% px4_noGPS4_DW.yaw
                    section.data(39).logicalSrcIdx = 57;
                    section.data(39).dtTransOffset = 38;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% px4_noGPS4_DW.Scope1_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 59;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS4_DW.Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 60;
                    section.data(2).dtTransOffset = 4;

                    ;% px4_noGPS4_DW.Scope2_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 61;
                    section.data(3).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% px4_noGPS4_DW.Subsystem1_SubsysRanBC
                    section.data(1).logicalSrcIdx = 62;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS4_DW.IfActionSubsystem2_SubsysRanBC
                    section.data(2).logicalSrcIdx = 63;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS4_DW.IfActionSubsystem1_SubsysRanBC
                    section.data(3).logicalSrcIdx = 64;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS4_DW.IfActionSubsystem_SubsysRanBC
                    section.data(4).logicalSrcIdx = 65;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS4_DW.EnabledSubsystem_SubsysRanBC
                    section.data(5).logicalSrcIdx = 66;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS4_DW.EnabledSubsystem_SubsysRanBC_b
                    section.data(6).logicalSrcIdx = 67;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% px4_noGPS4_DW.attitude_flag
                    section.data(1).logicalSrcIdx = 68;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS4_DW.position_flag
                    section.data(2).logicalSrcIdx = 70;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3900002089;
    targMap.checksum1 = 369837998;
    targMap.checksum2 = 3425623343;
    targMap.checksum3 = 3907751475;

