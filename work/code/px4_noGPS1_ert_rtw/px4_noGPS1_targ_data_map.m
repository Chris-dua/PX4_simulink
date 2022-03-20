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
        ;% Auto data (px4_noGPS1_P)
        ;%
            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% px4_noGPS1_P.DiscreteDerivative1_ICPrevScale
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS1_P.DiscreteDerivative1_ICPrevSca_o
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS1_P.DiscreteDerivative1_ICPrevSca_d
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS1_P.DiscreteDerivative_ICPrevScaled
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS1_P.DiscreteDerivative_ICPrevScal_g
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS1_P.CompareToConstant1_const
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS1_P.CompareToConstant1_const_b
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS1_P.CompareToConstant1_const_h
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS1_P.CompareToConstant2_const
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% px4_noGPS1_P.CompareToConstant1_const_hq
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% px4_noGPS1_P.CompareToConstant2_const_o
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% px4_noGPS1_P.CompareToConstant1_const_p
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% px4_noGPS1_P.CompareToConstant2_const_a
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% px4_noGPS1_P.CompareToConstant1_const_a
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS1_P.Out1_Y0
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS1_P.Constant_Value
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS1_P.Out1_Y0_k
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS1_P.Constant_Value_c
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 324;
            section.data(324)  = dumData; %prealloc

                    ;% px4_noGPS1_P.Constant1_Value
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS1_P.Constant1_Value_n
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS1_P.Constant1_Value_a
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS1_P.Saturation_UpperSat
                    section.data(4).logicalSrcIdx = 21;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS1_P.Saturation_LowerSat
                    section.data(5).logicalSrcIdx = 22;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS1_P.Constant_Value_b
                    section.data(6).logicalSrcIdx = 23;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS1_P.Constant3_Value
                    section.data(7).logicalSrcIdx = 24;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS1_P.Constant3_Value_a
                    section.data(8).logicalSrcIdx = 25;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS1_P.Constant3_Value_d
                    section.data(9).logicalSrcIdx = 26;
                    section.data(9).dtTransOffset = 8;

                    ;% px4_noGPS1_P.Constant1_Value_g
                    section.data(10).logicalSrcIdx = 27;
                    section.data(10).dtTransOffset = 9;

                    ;% px4_noGPS1_P.Constant1_Value_nr
                    section.data(11).logicalSrcIdx = 28;
                    section.data(11).dtTransOffset = 10;

                    ;% px4_noGPS1_P.Constant_Value_e
                    section.data(12).logicalSrcIdx = 29;
                    section.data(12).dtTransOffset = 11;

                    ;% px4_noGPS1_P.Constant_Value_b1
                    section.data(13).logicalSrcIdx = 30;
                    section.data(13).dtTransOffset = 12;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_gainval
                    section.data(14).logicalSrcIdx = 31;
                    section.data(14).dtTransOffset = 13;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_IC
                    section.data(15).logicalSrcIdx = 32;
                    section.data(15).dtTransOffset = 14;

                    ;% px4_noGPS1_P.Constant9_Value
                    section.data(16).logicalSrcIdx = 33;
                    section.data(16).dtTransOffset = 15;

                    ;% px4_noGPS1_P.Constant5_Value
                    section.data(17).logicalSrcIdx = 34;
                    section.data(17).dtTransOffset = 16;

                    ;% px4_noGPS1_P.Constant7_Value
                    section.data(18).logicalSrcIdx = 35;
                    section.data(18).dtTransOffset = 17;

                    ;% px4_noGPS1_P.Constant8_Value
                    section.data(19).logicalSrcIdx = 36;
                    section.data(19).dtTransOffset = 18;

                    ;% px4_noGPS1_P.DataStoreMemory33_InitialValue
                    section.data(20).logicalSrcIdx = 37;
                    section.data(20).dtTransOffset = 19;

                    ;% px4_noGPS1_P.DataStoreMemory34_InitialValue
                    section.data(21).logicalSrcIdx = 38;
                    section.data(21).dtTransOffset = 20;

                    ;% px4_noGPS1_P.DataStoreMemory35_InitialValue
                    section.data(22).logicalSrcIdx = 39;
                    section.data(22).dtTransOffset = 21;

                    ;% px4_noGPS1_P.DataStoreMemory5_InitialValue
                    section.data(23).logicalSrcIdx = 40;
                    section.data(23).dtTransOffset = 22;

                    ;% px4_noGPS1_P.r_Value
                    section.data(24).logicalSrcIdx = 41;
                    section.data(24).dtTransOffset = 23;

                    ;% px4_noGPS1_P.ch_Value
                    section.data(25).logicalSrcIdx = 42;
                    section.data(25).dtTransOffset = 24;

                    ;% px4_noGPS1_P.T_Value
                    section.data(26).logicalSrcIdx = 43;
                    section.data(26).dtTransOffset = 25;

                    ;% px4_noGPS1_P.t_Value
                    section.data(27).logicalSrcIdx = 44;
                    section.data(27).dtTransOffset = 26;

                    ;% px4_noGPS1_P.b_Value
                    section.data(28).logicalSrcIdx = 45;
                    section.data(28).dtTransOffset = 27;

                    ;% px4_noGPS1_P.Gain4_Gain
                    section.data(29).logicalSrcIdx = 46;
                    section.data(29).dtTransOffset = 28;

                    ;% px4_noGPS1_P.TSamp_WtEt
                    section.data(30).logicalSrcIdx = 47;
                    section.data(30).dtTransOffset = 29;

                    ;% px4_noGPS1_P.l_Value
                    section.data(31).logicalSrcIdx = 48;
                    section.data(31).dtTransOffset = 30;

                    ;% px4_noGPS1_P.Gain_Gain
                    section.data(32).logicalSrcIdx = 49;
                    section.data(32).dtTransOffset = 31;

                    ;% px4_noGPS1_P.Gain1_Gain
                    section.data(33).logicalSrcIdx = 50;
                    section.data(33).dtTransOffset = 32;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator3_gainval
                    section.data(34).logicalSrcIdx = 51;
                    section.data(34).dtTransOffset = 33;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator3_IC
                    section.data(35).logicalSrcIdx = 52;
                    section.data(35).dtTransOffset = 34;

                    ;% px4_noGPS1_P.Gain1_Gain_o
                    section.data(36).logicalSrcIdx = 53;
                    section.data(36).dtTransOffset = 35;

                    ;% px4_noGPS1_P.Saturation4_UpperSat
                    section.data(37).logicalSrcIdx = 54;
                    section.data(37).dtTransOffset = 36;

                    ;% px4_noGPS1_P.Saturation4_LowerSat
                    section.data(38).logicalSrcIdx = 55;
                    section.data(38).dtTransOffset = 37;

                    ;% px4_noGPS1_P.r_Value_g
                    section.data(39).logicalSrcIdx = 56;
                    section.data(39).dtTransOffset = 38;

                    ;% px4_noGPS1_P.ch_Value_j
                    section.data(40).logicalSrcIdx = 57;
                    section.data(40).dtTransOffset = 39;

                    ;% px4_noGPS1_P.T_Value_p
                    section.data(41).logicalSrcIdx = 58;
                    section.data(41).dtTransOffset = 40;

                    ;% px4_noGPS1_P.t_Value_n
                    section.data(42).logicalSrcIdx = 59;
                    section.data(42).dtTransOffset = 41;

                    ;% px4_noGPS1_P.b_Value_l
                    section.data(43).logicalSrcIdx = 60;
                    section.data(43).dtTransOffset = 42;

                    ;% px4_noGPS1_P.Gain4_Gain_b
                    section.data(44).logicalSrcIdx = 61;
                    section.data(44).dtTransOffset = 43;

                    ;% px4_noGPS1_P.TSamp_WtEt_p
                    section.data(45).logicalSrcIdx = 62;
                    section.data(45).dtTransOffset = 44;

                    ;% px4_noGPS1_P.l_Value_b
                    section.data(46).logicalSrcIdx = 63;
                    section.data(46).dtTransOffset = 45;

                    ;% px4_noGPS1_P.Gain_Gain_o
                    section.data(47).logicalSrcIdx = 64;
                    section.data(47).dtTransOffset = 46;

                    ;% px4_noGPS1_P.Gain1_Gain_b
                    section.data(48).logicalSrcIdx = 65;
                    section.data(48).dtTransOffset = 47;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator3_gainv_m
                    section.data(49).logicalSrcIdx = 66;
                    section.data(49).dtTransOffset = 48;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator3_IC_k
                    section.data(50).logicalSrcIdx = 67;
                    section.data(50).dtTransOffset = 49;

                    ;% px4_noGPS1_P.Gain2_Gain
                    section.data(51).logicalSrcIdx = 68;
                    section.data(51).dtTransOffset = 50;

                    ;% px4_noGPS1_P.r_Value_p
                    section.data(52).logicalSrcIdx = 69;
                    section.data(52).dtTransOffset = 51;

                    ;% px4_noGPS1_P.ch_Value_e
                    section.data(53).logicalSrcIdx = 70;
                    section.data(53).dtTransOffset = 52;

                    ;% px4_noGPS1_P.T_Value_c
                    section.data(54).logicalSrcIdx = 71;
                    section.data(54).dtTransOffset = 53;

                    ;% px4_noGPS1_P.t_Value_m
                    section.data(55).logicalSrcIdx = 72;
                    section.data(55).dtTransOffset = 54;

                    ;% px4_noGPS1_P.b_Value_h
                    section.data(56).logicalSrcIdx = 73;
                    section.data(56).dtTransOffset = 55;

                    ;% px4_noGPS1_P.Gain4_Gain_o
                    section.data(57).logicalSrcIdx = 74;
                    section.data(57).dtTransOffset = 56;

                    ;% px4_noGPS1_P.TSamp_WtEt_o
                    section.data(58).logicalSrcIdx = 75;
                    section.data(58).dtTransOffset = 57;

                    ;% px4_noGPS1_P.l_Value_n
                    section.data(59).logicalSrcIdx = 76;
                    section.data(59).dtTransOffset = 58;

                    ;% px4_noGPS1_P.Gain_Gain_m
                    section.data(60).logicalSrcIdx = 77;
                    section.data(60).dtTransOffset = 59;

                    ;% px4_noGPS1_P.J_Gain
                    section.data(61).logicalSrcIdx = 78;
                    section.data(61).dtTransOffset = 60;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator3_gainv_e
                    section.data(62).logicalSrcIdx = 79;
                    section.data(62).dtTransOffset = 61;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator3_IC_l
                    section.data(63).logicalSrcIdx = 80;
                    section.data(63).dtTransOffset = 62;

                    ;% px4_noGPS1_P.J_Gain_b
                    section.data(64).logicalSrcIdx = 81;
                    section.data(64).dtTransOffset = 63;

                    ;% px4_noGPS1_P.DataStoreMemory_InitialValue
                    section.data(65).logicalSrcIdx = 82;
                    section.data(65).dtTransOffset = 64;

                    ;% px4_noGPS1_P.DataStoreMemory_InitialValue_l
                    section.data(66).logicalSrcIdx = 83;
                    section.data(66).dtTransOffset = 65;

                    ;% px4_noGPS1_P.DataStoreMemory_InitialValue_b
                    section.data(67).logicalSrcIdx = 84;
                    section.data(67).dtTransOffset = 66;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_gainva_n
                    section.data(68).logicalSrcIdx = 85;
                    section.data(68).dtTransOffset = 67;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_IC_l
                    section.data(69).logicalSrcIdx = 86;
                    section.data(69).dtTransOffset = 68;

                    ;% px4_noGPS1_P.Gain2_Gain_c
                    section.data(70).logicalSrcIdx = 87;
                    section.data(70).dtTransOffset = 69;

                    ;% px4_noGPS1_P.uJ_Gain
                    section.data(71).logicalSrcIdx = 88;
                    section.data(71).dtTransOffset = 70;

                    ;% px4_noGPS1_P.kJ_Gain
                    section.data(72).logicalSrcIdx = 89;
                    section.data(72).dtTransOffset = 71;

                    ;% px4_noGPS1_P.Saturation_UpperSat_b
                    section.data(73).logicalSrcIdx = 90;
                    section.data(73).dtTransOffset = 72;

                    ;% px4_noGPS1_P.Saturation_LowerSat_k
                    section.data(74).logicalSrcIdx = 91;
                    section.data(74).dtTransOffset = 73;

                    ;% px4_noGPS1_P.l1_Gain
                    section.data(75).logicalSrcIdx = 92;
                    section.data(75).dtTransOffset = 74;

                    ;% px4_noGPS1_P.lambda1_Gain
                    section.data(76).logicalSrcIdx = 93;
                    section.data(76).dtTransOffset = 75;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator1_gainval
                    section.data(77).logicalSrcIdx = 94;
                    section.data(77).dtTransOffset = 76;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator1_IC
                    section.data(78).logicalSrcIdx = 95;
                    section.data(78).dtTransOffset = 77;

                    ;% px4_noGPS1_P.Constant1_Value_f
                    section.data(79).logicalSrcIdx = 96;
                    section.data(79).dtTransOffset = 78;

                    ;% px4_noGPS1_P.Saturation10_UpperSat
                    section.data(80).logicalSrcIdx = 97;
                    section.data(80).dtTransOffset = 79;

                    ;% px4_noGPS1_P.Saturation10_LowerSat
                    section.data(81).logicalSrcIdx = 98;
                    section.data(81).dtTransOffset = 80;

                    ;% px4_noGPS1_P.Saturation11_UpperSat
                    section.data(82).logicalSrcIdx = 99;
                    section.data(82).dtTransOffset = 81;

                    ;% px4_noGPS1_P.Saturation11_LowerSat
                    section.data(83).logicalSrcIdx = 100;
                    section.data(83).dtTransOffset = 82;

                    ;% px4_noGPS1_P.Gain_Gain_ml
                    section.data(84).logicalSrcIdx = 101;
                    section.data(84).dtTransOffset = 83;

                    ;% px4_noGPS1_P.Saturation8_UpperSat
                    section.data(85).logicalSrcIdx = 102;
                    section.data(85).dtTransOffset = 84;

                    ;% px4_noGPS1_P.Saturation8_LowerSat
                    section.data(86).logicalSrcIdx = 103;
                    section.data(86).dtTransOffset = 85;

                    ;% px4_noGPS1_P.Constant2_Value
                    section.data(87).logicalSrcIdx = 104;
                    section.data(87).dtTransOffset = 86;

                    ;% px4_noGPS1_P.Gain5_Gain
                    section.data(88).logicalSrcIdx = 105;
                    section.data(88).dtTransOffset = 87;

                    ;% px4_noGPS1_P.Saturation13_UpperSat
                    section.data(89).logicalSrcIdx = 106;
                    section.data(89).dtTransOffset = 88;

                    ;% px4_noGPS1_P.Saturation13_LowerSat
                    section.data(90).logicalSrcIdx = 107;
                    section.data(90).dtTransOffset = 89;

                    ;% px4_noGPS1_P.Saturation9_UpperSat
                    section.data(91).logicalSrcIdx = 108;
                    section.data(91).dtTransOffset = 90;

                    ;% px4_noGPS1_P.Saturation9_LowerSat
                    section.data(92).logicalSrcIdx = 109;
                    section.data(92).dtTransOffset = 91;

                    ;% px4_noGPS1_P.Gain1_Gain_a
                    section.data(93).logicalSrcIdx = 110;
                    section.data(93).dtTransOffset = 92;

                    ;% px4_noGPS1_P.Constant4_Value
                    section.data(94).logicalSrcIdx = 111;
                    section.data(94).dtTransOffset = 93;

                    ;% px4_noGPS1_P.Saturation12_UpperSat
                    section.data(95).logicalSrcIdx = 112;
                    section.data(95).dtTransOffset = 94;

                    ;% px4_noGPS1_P.Saturation12_LowerSat
                    section.data(96).logicalSrcIdx = 113;
                    section.data(96).dtTransOffset = 95;

                    ;% px4_noGPS1_P.Saturation16_UpperSat
                    section.data(97).logicalSrcIdx = 114;
                    section.data(97).dtTransOffset = 96;

                    ;% px4_noGPS1_P.Saturation16_LowerSat
                    section.data(98).logicalSrcIdx = 115;
                    section.data(98).dtTransOffset = 97;

                    ;% px4_noGPS1_P.Saturation14_UpperSat
                    section.data(99).logicalSrcIdx = 116;
                    section.data(99).dtTransOffset = 98;

                    ;% px4_noGPS1_P.Saturation14_LowerSat
                    section.data(100).logicalSrcIdx = 117;
                    section.data(100).dtTransOffset = 99;

                    ;% px4_noGPS1_P.Gain3_Gain
                    section.data(101).logicalSrcIdx = 118;
                    section.data(101).dtTransOffset = 100;

                    ;% px4_noGPS1_P.Constant6_Value
                    section.data(102).logicalSrcIdx = 119;
                    section.data(102).dtTransOffset = 101;

                    ;% px4_noGPS1_P.lambda2_Gain
                    section.data(103).logicalSrcIdx = 120;
                    section.data(103).dtTransOffset = 102;

                    ;% px4_noGPS1_P.Saturation1_UpperSat
                    section.data(104).logicalSrcIdx = 121;
                    section.data(104).dtTransOffset = 103;

                    ;% px4_noGPS1_P.Saturation1_LowerSat
                    section.data(105).logicalSrcIdx = 122;
                    section.data(105).dtTransOffset = 104;

                    ;% px4_noGPS1_P.l2_Gain
                    section.data(106).logicalSrcIdx = 123;
                    section.data(106).dtTransOffset = 105;

                    ;% px4_noGPS1_P.Saturation15_UpperSat
                    section.data(107).logicalSrcIdx = 124;
                    section.data(107).dtTransOffset = 106;

                    ;% px4_noGPS1_P.Saturation15_LowerSat
                    section.data(108).logicalSrcIdx = 125;
                    section.data(108).dtTransOffset = 107;

                    ;% px4_noGPS1_P.Gain6_Gain
                    section.data(109).logicalSrcIdx = 126;
                    section.data(109).dtTransOffset = 108;

                    ;% px4_noGPS1_P.Saturation19_UpperSat
                    section.data(110).logicalSrcIdx = 127;
                    section.data(110).dtTransOffset = 109;

                    ;% px4_noGPS1_P.Saturation19_LowerSat
                    section.data(111).logicalSrcIdx = 128;
                    section.data(111).dtTransOffset = 110;

                    ;% px4_noGPS1_P.Saturation17_UpperSat
                    section.data(112).logicalSrcIdx = 129;
                    section.data(112).dtTransOffset = 111;

                    ;% px4_noGPS1_P.Saturation17_LowerSat
                    section.data(113).logicalSrcIdx = 130;
                    section.data(113).dtTransOffset = 112;

                    ;% px4_noGPS1_P.Gain4_Gain_f
                    section.data(114).logicalSrcIdx = 131;
                    section.data(114).dtTransOffset = 113;

                    ;% px4_noGPS1_P.Constant8_Value_j
                    section.data(115).logicalSrcIdx = 132;
                    section.data(115).dtTransOffset = 114;

                    ;% px4_noGPS1_P.Saturation18_UpperSat
                    section.data(116).logicalSrcIdx = 133;
                    section.data(116).dtTransOffset = 115;

                    ;% px4_noGPS1_P.Saturation18_LowerSat
                    section.data(117).logicalSrcIdx = 134;
                    section.data(117).dtTransOffset = 116;

                    ;% px4_noGPS1_P.Saturation3_UpperSat
                    section.data(118).logicalSrcIdx = 135;
                    section.data(118).dtTransOffset = 117;

                    ;% px4_noGPS1_P.Saturation3_LowerSat
                    section.data(119).logicalSrcIdx = 136;
                    section.data(119).dtTransOffset = 118;

                    ;% px4_noGPS1_P.l4_Gain
                    section.data(120).logicalSrcIdx = 137;
                    section.data(120).dtTransOffset = 119;

                    ;% px4_noGPS1_P.lambda4_Gain
                    section.data(121).logicalSrcIdx = 138;
                    section.data(121).dtTransOffset = 120;

                    ;% px4_noGPS1_P.Gain7_Gain
                    section.data(122).logicalSrcIdx = 139;
                    section.data(122).dtTransOffset = 121;

                    ;% px4_noGPS1_P.Gain8_Gain
                    section.data(123).logicalSrcIdx = 140;
                    section.data(123).dtTransOffset = 122;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_gainva_e
                    section.data(124).logicalSrcIdx = 141;
                    section.data(124).dtTransOffset = 123;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_IC_h
                    section.data(125).logicalSrcIdx = 142;
                    section.data(125).dtTransOffset = 124;

                    ;% px4_noGPS1_P.Gain2_Gain_g
                    section.data(126).logicalSrcIdx = 143;
                    section.data(126).dtTransOffset = 125;

                    ;% px4_noGPS1_P.uJ_Gain_p
                    section.data(127).logicalSrcIdx = 144;
                    section.data(127).dtTransOffset = 126;

                    ;% px4_noGPS1_P.kJ_Gain_c
                    section.data(128).logicalSrcIdx = 145;
                    section.data(128).dtTransOffset = 127;

                    ;% px4_noGPS1_P.Saturation_UpperSat_n
                    section.data(129).logicalSrcIdx = 146;
                    section.data(129).dtTransOffset = 128;

                    ;% px4_noGPS1_P.Saturation_LowerSat_g
                    section.data(130).logicalSrcIdx = 147;
                    section.data(130).dtTransOffset = 129;

                    ;% px4_noGPS1_P.l1_Gain_p
                    section.data(131).logicalSrcIdx = 148;
                    section.data(131).dtTransOffset = 130;

                    ;% px4_noGPS1_P.lambda1_Gain_a
                    section.data(132).logicalSrcIdx = 149;
                    section.data(132).dtTransOffset = 131;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator1_gainv_n
                    section.data(133).logicalSrcIdx = 150;
                    section.data(133).dtTransOffset = 132;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator1_IC_j
                    section.data(134).logicalSrcIdx = 151;
                    section.data(134).dtTransOffset = 133;

                    ;% px4_noGPS1_P.Constant1_Value_j
                    section.data(135).logicalSrcIdx = 152;
                    section.data(135).dtTransOffset = 134;

                    ;% px4_noGPS1_P.Saturation10_UpperSat_o
                    section.data(136).logicalSrcIdx = 153;
                    section.data(136).dtTransOffset = 135;

                    ;% px4_noGPS1_P.Saturation10_LowerSat_b
                    section.data(137).logicalSrcIdx = 154;
                    section.data(137).dtTransOffset = 136;

                    ;% px4_noGPS1_P.Saturation11_UpperSat_p
                    section.data(138).logicalSrcIdx = 155;
                    section.data(138).dtTransOffset = 137;

                    ;% px4_noGPS1_P.Saturation11_LowerSat_i
                    section.data(139).logicalSrcIdx = 156;
                    section.data(139).dtTransOffset = 138;

                    ;% px4_noGPS1_P.Gain_Gain_g
                    section.data(140).logicalSrcIdx = 157;
                    section.data(140).dtTransOffset = 139;

                    ;% px4_noGPS1_P.Saturation8_UpperSat_g
                    section.data(141).logicalSrcIdx = 158;
                    section.data(141).dtTransOffset = 140;

                    ;% px4_noGPS1_P.Saturation8_LowerSat_g
                    section.data(142).logicalSrcIdx = 159;
                    section.data(142).dtTransOffset = 141;

                    ;% px4_noGPS1_P.Constant2_Value_h
                    section.data(143).logicalSrcIdx = 160;
                    section.data(143).dtTransOffset = 142;

                    ;% px4_noGPS1_P.Gain5_Gain_o
                    section.data(144).logicalSrcIdx = 161;
                    section.data(144).dtTransOffset = 143;

                    ;% px4_noGPS1_P.Saturation13_UpperSat_i
                    section.data(145).logicalSrcIdx = 162;
                    section.data(145).dtTransOffset = 144;

                    ;% px4_noGPS1_P.Saturation13_LowerSat_c
                    section.data(146).logicalSrcIdx = 163;
                    section.data(146).dtTransOffset = 145;

                    ;% px4_noGPS1_P.Saturation9_UpperSat_i
                    section.data(147).logicalSrcIdx = 164;
                    section.data(147).dtTransOffset = 146;

                    ;% px4_noGPS1_P.Saturation9_LowerSat_c
                    section.data(148).logicalSrcIdx = 165;
                    section.data(148).dtTransOffset = 147;

                    ;% px4_noGPS1_P.Gain1_Gain_d
                    section.data(149).logicalSrcIdx = 166;
                    section.data(149).dtTransOffset = 148;

                    ;% px4_noGPS1_P.Constant4_Value_n
                    section.data(150).logicalSrcIdx = 167;
                    section.data(150).dtTransOffset = 149;

                    ;% px4_noGPS1_P.Saturation12_UpperSat_c
                    section.data(151).logicalSrcIdx = 168;
                    section.data(151).dtTransOffset = 150;

                    ;% px4_noGPS1_P.Saturation12_LowerSat_b
                    section.data(152).logicalSrcIdx = 169;
                    section.data(152).dtTransOffset = 151;

                    ;% px4_noGPS1_P.Saturation16_UpperSat_l
                    section.data(153).logicalSrcIdx = 170;
                    section.data(153).dtTransOffset = 152;

                    ;% px4_noGPS1_P.Saturation16_LowerSat_g
                    section.data(154).logicalSrcIdx = 171;
                    section.data(154).dtTransOffset = 153;

                    ;% px4_noGPS1_P.Saturation14_UpperSat_l
                    section.data(155).logicalSrcIdx = 172;
                    section.data(155).dtTransOffset = 154;

                    ;% px4_noGPS1_P.Saturation14_LowerSat_b
                    section.data(156).logicalSrcIdx = 173;
                    section.data(156).dtTransOffset = 155;

                    ;% px4_noGPS1_P.Gain3_Gain_l
                    section.data(157).logicalSrcIdx = 174;
                    section.data(157).dtTransOffset = 156;

                    ;% px4_noGPS1_P.Constant6_Value_o
                    section.data(158).logicalSrcIdx = 175;
                    section.data(158).dtTransOffset = 157;

                    ;% px4_noGPS1_P.lambda2_Gain_j
                    section.data(159).logicalSrcIdx = 176;
                    section.data(159).dtTransOffset = 158;

                    ;% px4_noGPS1_P.Saturation1_UpperSat_a
                    section.data(160).logicalSrcIdx = 177;
                    section.data(160).dtTransOffset = 159;

                    ;% px4_noGPS1_P.Saturation1_LowerSat_i
                    section.data(161).logicalSrcIdx = 178;
                    section.data(161).dtTransOffset = 160;

                    ;% px4_noGPS1_P.l2_Gain_l
                    section.data(162).logicalSrcIdx = 179;
                    section.data(162).dtTransOffset = 161;

                    ;% px4_noGPS1_P.Saturation15_UpperSat_j
                    section.data(163).logicalSrcIdx = 180;
                    section.data(163).dtTransOffset = 162;

                    ;% px4_noGPS1_P.Saturation15_LowerSat_k
                    section.data(164).logicalSrcIdx = 181;
                    section.data(164).dtTransOffset = 163;

                    ;% px4_noGPS1_P.Gain6_Gain_e
                    section.data(165).logicalSrcIdx = 182;
                    section.data(165).dtTransOffset = 164;

                    ;% px4_noGPS1_P.Saturation19_UpperSat_b
                    section.data(166).logicalSrcIdx = 183;
                    section.data(166).dtTransOffset = 165;

                    ;% px4_noGPS1_P.Saturation19_LowerSat_j
                    section.data(167).logicalSrcIdx = 184;
                    section.data(167).dtTransOffset = 166;

                    ;% px4_noGPS1_P.Saturation17_UpperSat_d
                    section.data(168).logicalSrcIdx = 185;
                    section.data(168).dtTransOffset = 167;

                    ;% px4_noGPS1_P.Saturation17_LowerSat_o
                    section.data(169).logicalSrcIdx = 186;
                    section.data(169).dtTransOffset = 168;

                    ;% px4_noGPS1_P.Gain4_Gain_n
                    section.data(170).logicalSrcIdx = 187;
                    section.data(170).dtTransOffset = 169;

                    ;% px4_noGPS1_P.Constant8_Value_f
                    section.data(171).logicalSrcIdx = 188;
                    section.data(171).dtTransOffset = 170;

                    ;% px4_noGPS1_P.Saturation18_UpperSat_a
                    section.data(172).logicalSrcIdx = 189;
                    section.data(172).dtTransOffset = 171;

                    ;% px4_noGPS1_P.Saturation18_LowerSat_h
                    section.data(173).logicalSrcIdx = 190;
                    section.data(173).dtTransOffset = 172;

                    ;% px4_noGPS1_P.Saturation3_UpperSat_m
                    section.data(174).logicalSrcIdx = 191;
                    section.data(174).dtTransOffset = 173;

                    ;% px4_noGPS1_P.Saturation3_LowerSat_i
                    section.data(175).logicalSrcIdx = 192;
                    section.data(175).dtTransOffset = 174;

                    ;% px4_noGPS1_P.l4_Gain_p
                    section.data(176).logicalSrcIdx = 193;
                    section.data(176).dtTransOffset = 175;

                    ;% px4_noGPS1_P.lambda4_Gain_a
                    section.data(177).logicalSrcIdx = 194;
                    section.data(177).dtTransOffset = 176;

                    ;% px4_noGPS1_P.Gain7_Gain_d
                    section.data(178).logicalSrcIdx = 195;
                    section.data(178).dtTransOffset = 177;

                    ;% px4_noGPS1_P.Gain8_Gain_b
                    section.data(179).logicalSrcIdx = 196;
                    section.data(179).dtTransOffset = 178;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_gainv_nv
                    section.data(180).logicalSrcIdx = 197;
                    section.data(180).dtTransOffset = 179;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_IC_o
                    section.data(181).logicalSrcIdx = 198;
                    section.data(181).dtTransOffset = 180;

                    ;% px4_noGPS1_P.Gain2_Gain_p
                    section.data(182).logicalSrcIdx = 199;
                    section.data(182).dtTransOffset = 181;

                    ;% px4_noGPS1_P.uJ_Gain_g
                    section.data(183).logicalSrcIdx = 200;
                    section.data(183).dtTransOffset = 182;

                    ;% px4_noGPS1_P.kJ_Gain_p
                    section.data(184).logicalSrcIdx = 201;
                    section.data(184).dtTransOffset = 183;

                    ;% px4_noGPS1_P.Saturation_UpperSat_n1
                    section.data(185).logicalSrcIdx = 202;
                    section.data(185).dtTransOffset = 184;

                    ;% px4_noGPS1_P.Saturation_LowerSat_c
                    section.data(186).logicalSrcIdx = 203;
                    section.data(186).dtTransOffset = 185;

                    ;% px4_noGPS1_P.l1_Gain_d
                    section.data(187).logicalSrcIdx = 204;
                    section.data(187).dtTransOffset = 186;

                    ;% px4_noGPS1_P.lambda1_Gain_g
                    section.data(188).logicalSrcIdx = 205;
                    section.data(188).dtTransOffset = 187;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator1_gainv_g
                    section.data(189).logicalSrcIdx = 206;
                    section.data(189).dtTransOffset = 188;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator1_IC_c
                    section.data(190).logicalSrcIdx = 207;
                    section.data(190).dtTransOffset = 189;

                    ;% px4_noGPS1_P.Constant1_Value_ac
                    section.data(191).logicalSrcIdx = 208;
                    section.data(191).dtTransOffset = 190;

                    ;% px4_noGPS1_P.Saturation10_UpperSat_a
                    section.data(192).logicalSrcIdx = 209;
                    section.data(192).dtTransOffset = 191;

                    ;% px4_noGPS1_P.Saturation10_LowerSat_l
                    section.data(193).logicalSrcIdx = 210;
                    section.data(193).dtTransOffset = 192;

                    ;% px4_noGPS1_P.Saturation11_UpperSat_a
                    section.data(194).logicalSrcIdx = 211;
                    section.data(194).dtTransOffset = 193;

                    ;% px4_noGPS1_P.Saturation11_LowerSat_a
                    section.data(195).logicalSrcIdx = 212;
                    section.data(195).dtTransOffset = 194;

                    ;% px4_noGPS1_P.Gain_Gain_h
                    section.data(196).logicalSrcIdx = 213;
                    section.data(196).dtTransOffset = 195;

                    ;% px4_noGPS1_P.Saturation8_UpperSat_c
                    section.data(197).logicalSrcIdx = 214;
                    section.data(197).dtTransOffset = 196;

                    ;% px4_noGPS1_P.Saturation8_LowerSat_c
                    section.data(198).logicalSrcIdx = 215;
                    section.data(198).dtTransOffset = 197;

                    ;% px4_noGPS1_P.Constant2_Value_k
                    section.data(199).logicalSrcIdx = 216;
                    section.data(199).dtTransOffset = 198;

                    ;% px4_noGPS1_P.Gain5_Gain_l
                    section.data(200).logicalSrcIdx = 217;
                    section.data(200).dtTransOffset = 199;

                    ;% px4_noGPS1_P.Saturation13_UpperSat_p
                    section.data(201).logicalSrcIdx = 218;
                    section.data(201).dtTransOffset = 200;

                    ;% px4_noGPS1_P.Saturation13_LowerSat_j
                    section.data(202).logicalSrcIdx = 219;
                    section.data(202).dtTransOffset = 201;

                    ;% px4_noGPS1_P.Saturation9_UpperSat_d
                    section.data(203).logicalSrcIdx = 220;
                    section.data(203).dtTransOffset = 202;

                    ;% px4_noGPS1_P.Saturation9_LowerSat_c4
                    section.data(204).logicalSrcIdx = 221;
                    section.data(204).dtTransOffset = 203;

                    ;% px4_noGPS1_P.Gain1_Gain_e
                    section.data(205).logicalSrcIdx = 222;
                    section.data(205).dtTransOffset = 204;

                    ;% px4_noGPS1_P.Constant4_Value_l
                    section.data(206).logicalSrcIdx = 223;
                    section.data(206).dtTransOffset = 205;

                    ;% px4_noGPS1_P.Saturation12_UpperSat_d
                    section.data(207).logicalSrcIdx = 224;
                    section.data(207).dtTransOffset = 206;

                    ;% px4_noGPS1_P.Saturation12_LowerSat_j
                    section.data(208).logicalSrcIdx = 225;
                    section.data(208).dtTransOffset = 207;

                    ;% px4_noGPS1_P.Saturation16_UpperSat_p
                    section.data(209).logicalSrcIdx = 226;
                    section.data(209).dtTransOffset = 208;

                    ;% px4_noGPS1_P.Saturation16_LowerSat_i
                    section.data(210).logicalSrcIdx = 227;
                    section.data(210).dtTransOffset = 209;

                    ;% px4_noGPS1_P.Saturation14_UpperSat_n
                    section.data(211).logicalSrcIdx = 228;
                    section.data(211).dtTransOffset = 210;

                    ;% px4_noGPS1_P.Saturation14_LowerSat_a
                    section.data(212).logicalSrcIdx = 229;
                    section.data(212).dtTransOffset = 211;

                    ;% px4_noGPS1_P.Gain3_Gain_p
                    section.data(213).logicalSrcIdx = 230;
                    section.data(213).dtTransOffset = 212;

                    ;% px4_noGPS1_P.Constant6_Value_g
                    section.data(214).logicalSrcIdx = 231;
                    section.data(214).dtTransOffset = 213;

                    ;% px4_noGPS1_P.lambda2_Gain_d
                    section.data(215).logicalSrcIdx = 232;
                    section.data(215).dtTransOffset = 214;

                    ;% px4_noGPS1_P.Saturation1_UpperSat_d
                    section.data(216).logicalSrcIdx = 233;
                    section.data(216).dtTransOffset = 215;

                    ;% px4_noGPS1_P.Saturation1_LowerSat_g
                    section.data(217).logicalSrcIdx = 234;
                    section.data(217).dtTransOffset = 216;

                    ;% px4_noGPS1_P.l2_Gain_i
                    section.data(218).logicalSrcIdx = 235;
                    section.data(218).dtTransOffset = 217;

                    ;% px4_noGPS1_P.Saturation15_UpperSat_k
                    section.data(219).logicalSrcIdx = 236;
                    section.data(219).dtTransOffset = 218;

                    ;% px4_noGPS1_P.Saturation15_LowerSat_h
                    section.data(220).logicalSrcIdx = 237;
                    section.data(220).dtTransOffset = 219;

                    ;% px4_noGPS1_P.Gain6_Gain_f
                    section.data(221).logicalSrcIdx = 238;
                    section.data(221).dtTransOffset = 220;

                    ;% px4_noGPS1_P.Saturation19_UpperSat_bc
                    section.data(222).logicalSrcIdx = 239;
                    section.data(222).dtTransOffset = 221;

                    ;% px4_noGPS1_P.Saturation19_LowerSat_e
                    section.data(223).logicalSrcIdx = 240;
                    section.data(223).dtTransOffset = 222;

                    ;% px4_noGPS1_P.Saturation17_UpperSat_o
                    section.data(224).logicalSrcIdx = 241;
                    section.data(224).dtTransOffset = 223;

                    ;% px4_noGPS1_P.Saturation17_LowerSat_m
                    section.data(225).logicalSrcIdx = 242;
                    section.data(225).dtTransOffset = 224;

                    ;% px4_noGPS1_P.Gain4_Gain_e
                    section.data(226).logicalSrcIdx = 243;
                    section.data(226).dtTransOffset = 225;

                    ;% px4_noGPS1_P.Constant8_Value_p
                    section.data(227).logicalSrcIdx = 244;
                    section.data(227).dtTransOffset = 226;

                    ;% px4_noGPS1_P.Saturation18_UpperSat_c
                    section.data(228).logicalSrcIdx = 245;
                    section.data(228).dtTransOffset = 227;

                    ;% px4_noGPS1_P.Saturation18_LowerSat_g
                    section.data(229).logicalSrcIdx = 246;
                    section.data(229).dtTransOffset = 228;

                    ;% px4_noGPS1_P.Saturation3_UpperSat_i
                    section.data(230).logicalSrcIdx = 247;
                    section.data(230).dtTransOffset = 229;

                    ;% px4_noGPS1_P.Saturation3_LowerSat_g
                    section.data(231).logicalSrcIdx = 248;
                    section.data(231).dtTransOffset = 230;

                    ;% px4_noGPS1_P.l4_Gain_o
                    section.data(232).logicalSrcIdx = 249;
                    section.data(232).dtTransOffset = 231;

                    ;% px4_noGPS1_P.lambda4_Gain_b
                    section.data(233).logicalSrcIdx = 250;
                    section.data(233).dtTransOffset = 232;

                    ;% px4_noGPS1_P.Gain7_Gain_l
                    section.data(234).logicalSrcIdx = 251;
                    section.data(234).dtTransOffset = 233;

                    ;% px4_noGPS1_P.Gain8_Gain_o
                    section.data(235).logicalSrcIdx = 252;
                    section.data(235).dtTransOffset = 234;

                    ;% px4_noGPS1_P.Saturation2_UpperSat
                    section.data(236).logicalSrcIdx = 253;
                    section.data(236).dtTransOffset = 235;

                    ;% px4_noGPS1_P.Saturation2_LowerSat
                    section.data(237).logicalSrcIdx = 254;
                    section.data(237).dtTransOffset = 236;

                    ;% px4_noGPS1_P.e_pitch_InitialValue
                    section.data(238).logicalSrcIdx = 255;
                    section.data(238).dtTransOffset = 237;

                    ;% px4_noGPS1_P.e_pitch1_InitialValue
                    section.data(239).logicalSrcIdx = 256;
                    section.data(239).dtTransOffset = 238;

                    ;% px4_noGPS1_P.e_pitch2_InitialValue
                    section.data(240).logicalSrcIdx = 257;
                    section.data(240).dtTransOffset = 239;

                    ;% px4_noGPS1_P.Intgrt_dX_gainval
                    section.data(241).logicalSrcIdx = 258;
                    section.data(241).dtTransOffset = 240;

                    ;% px4_noGPS1_P.Intgrt_dX_IC
                    section.data(242).logicalSrcIdx = 259;
                    section.data(242).dtTransOffset = 241;

                    ;% px4_noGPS1_P.Intgrt_dY_gainval
                    section.data(243).logicalSrcIdx = 260;
                    section.data(243).dtTransOffset = 242;

                    ;% px4_noGPS1_P.Intgrt_dY_IC
                    section.data(244).logicalSrcIdx = 261;
                    section.data(244).dtTransOffset = 243;

                    ;% px4_noGPS1_P.Intgrt_ddY_gainval
                    section.data(245).logicalSrcIdx = 262;
                    section.data(245).dtTransOffset = 244;

                    ;% px4_noGPS1_P.Intgrt_ddY_IC
                    section.data(246).logicalSrcIdx = 263;
                    section.data(246).dtTransOffset = 245;

                    ;% px4_noGPS1_P.Intgrt_ddX_gainval
                    section.data(247).logicalSrcIdx = 264;
                    section.data(247).dtTransOffset = 246;

                    ;% px4_noGPS1_P.Intgrt_ddX_IC
                    section.data(248).logicalSrcIdx = 265;
                    section.data(248).dtTransOffset = 247;

                    ;% px4_noGPS1_P.Constant6_Value_p
                    section.data(249).logicalSrcIdx = 266;
                    section.data(249).dtTransOffset = 248;

                    ;% px4_noGPS1_P.C1_Gain
                    section.data(250).logicalSrcIdx = 267;
                    section.data(250).dtTransOffset = 249;

                    ;% px4_noGPS1_P.TSamp_WtEt_d
                    section.data(251).logicalSrcIdx = 268;
                    section.data(251).dtTransOffset = 250;

                    ;% px4_noGPS1_P.C2_Gain
                    section.data(252).logicalSrcIdx = 269;
                    section.data(252).dtTransOffset = 251;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_gainva_h
                    section.data(253).logicalSrcIdx = 270;
                    section.data(253).dtTransOffset = 252;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_IC_f
                    section.data(254).logicalSrcIdx = 271;
                    section.data(254).dtTransOffset = 253;

                    ;% px4_noGPS1_P.C3_Gain
                    section.data(255).logicalSrcIdx = 272;
                    section.data(255).dtTransOffset = 254;

                    ;% px4_noGPS1_P.Gain2_Gain_d
                    section.data(256).logicalSrcIdx = 273;
                    section.data(256).dtTransOffset = 255;

                    ;% px4_noGPS1_P.Saturation1_UpperSat_h
                    section.data(257).logicalSrcIdx = 274;
                    section.data(257).dtTransOffset = 256;

                    ;% px4_noGPS1_P.Saturation1_LowerSat_o
                    section.data(258).logicalSrcIdx = 275;
                    section.data(258).dtTransOffset = 257;

                    ;% px4_noGPS1_P.Constant_Value_i
                    section.data(259).logicalSrcIdx = 276;
                    section.data(259).dtTransOffset = 258;

                    ;% px4_noGPS1_P.C1_Gain_d
                    section.data(260).logicalSrcIdx = 277;
                    section.data(260).dtTransOffset = 259;

                    ;% px4_noGPS1_P.TSamp_WtEt_e
                    section.data(261).logicalSrcIdx = 278;
                    section.data(261).dtTransOffset = 260;

                    ;% px4_noGPS1_P.C2_Gain_b
                    section.data(262).logicalSrcIdx = 279;
                    section.data(262).dtTransOffset = 261;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_gainva_p
                    section.data(263).logicalSrcIdx = 280;
                    section.data(263).dtTransOffset = 262;

                    ;% px4_noGPS1_P.DiscreteTimeIntegrator_IC_ff
                    section.data(264).logicalSrcIdx = 281;
                    section.data(264).dtTransOffset = 263;

                    ;% px4_noGPS1_P.C3_Gain_j
                    section.data(265).logicalSrcIdx = 282;
                    section.data(265).dtTransOffset = 264;

                    ;% px4_noGPS1_P.Gain4_Gain_ff
                    section.data(266).logicalSrcIdx = 283;
                    section.data(266).dtTransOffset = 265;

                    ;% px4_noGPS1_P.Saturation2_UpperSat_c
                    section.data(267).logicalSrcIdx = 284;
                    section.data(267).dtTransOffset = 266;

                    ;% px4_noGPS1_P.Saturation2_LowerSat_f
                    section.data(268).logicalSrcIdx = 285;
                    section.data(268).dtTransOffset = 267;

                    ;% px4_noGPS1_P.Saturation2_UpperSat_o
                    section.data(269).logicalSrcIdx = 286;
                    section.data(269).dtTransOffset = 268;

                    ;% px4_noGPS1_P.Saturation2_LowerSat_b
                    section.data(270).logicalSrcIdx = 287;
                    section.data(270).dtTransOffset = 269;

                    ;% px4_noGPS1_P.Saturation_UpperSat_bm
                    section.data(271).logicalSrcIdx = 288;
                    section.data(271).dtTransOffset = 270;

                    ;% px4_noGPS1_P.Saturation_LowerSat_co
                    section.data(272).logicalSrcIdx = 289;
                    section.data(272).dtTransOffset = 271;

                    ;% px4_noGPS1_P.fault_1_Value
                    section.data(273).logicalSrcIdx = 290;
                    section.data(273).dtTransOffset = 272;

                    ;% px4_noGPS1_P.Mixermatrix1_Value
                    section.data(274).logicalSrcIdx = 291;
                    section.data(274).dtTransOffset = 273;

                    ;% px4_noGPS1_P.Gain4_Gain_fc
                    section.data(275).logicalSrcIdx = 292;
                    section.data(275).dtTransOffset = 289;

                    ;% px4_noGPS1_P.fault_2_Value
                    section.data(276).logicalSrcIdx = 293;
                    section.data(276).dtTransOffset = 290;

                    ;% px4_noGPS1_P.fault_3_Value
                    section.data(277).logicalSrcIdx = 294;
                    section.data(277).dtTransOffset = 291;

                    ;% px4_noGPS1_P.fault_4_Value
                    section.data(278).logicalSrcIdx = 295;
                    section.data(278).dtTransOffset = 292;

                    ;% px4_noGPS1_P.Intgrt_dZ_gainval
                    section.data(279).logicalSrcIdx = 296;
                    section.data(279).dtTransOffset = 293;

                    ;% px4_noGPS1_P.Intgrt_dZ_IC
                    section.data(280).logicalSrcIdx = 297;
                    section.data(280).dtTransOffset = 294;

                    ;% px4_noGPS1_P.Intgrt_ddZ_gainval
                    section.data(281).logicalSrcIdx = 298;
                    section.data(281).dtTransOffset = 295;

                    ;% px4_noGPS1_P.Intgrt_ddZ_IC
                    section.data(282).logicalSrcIdx = 299;
                    section.data(282).dtTransOffset = 296;

                    ;% px4_noGPS1_P.Saturation1_UpperSat_k
                    section.data(283).logicalSrcIdx = 300;
                    section.data(283).dtTransOffset = 297;

                    ;% px4_noGPS1_P.Saturation1_LowerSat_c
                    section.data(284).logicalSrcIdx = 301;
                    section.data(284).dtTransOffset = 298;

                    ;% px4_noGPS1_P.slower3_Gain
                    section.data(285).logicalSrcIdx = 302;
                    section.data(285).dtTransOffset = 299;

                    ;% px4_noGPS1_P.slower4_Gain
                    section.data(286).logicalSrcIdx = 303;
                    section.data(286).dtTransOffset = 300;

                    ;% px4_noGPS1_P.slower5_Gain
                    section.data(287).logicalSrcIdx = 304;
                    section.data(287).dtTransOffset = 301;

                    ;% px4_noGPS1_P.Gain5_Gain_g
                    section.data(288).logicalSrcIdx = 305;
                    section.data(288).dtTransOffset = 302;

                    ;% px4_noGPS1_P.Gain3_Gain_c
                    section.data(289).logicalSrcIdx = 306;
                    section.data(289).dtTransOffset = 303;

                    ;% px4_noGPS1_P.Gain6_Gain_k
                    section.data(290).logicalSrcIdx = 307;
                    section.data(290).dtTransOffset = 304;

                    ;% px4_noGPS1_P.Gain8_Gain_o1
                    section.data(291).logicalSrcIdx = 308;
                    section.data(291).dtTransOffset = 305;

                    ;% px4_noGPS1_P.Gain10_Gain
                    section.data(292).logicalSrcIdx = 309;
                    section.data(292).dtTransOffset = 306;

                    ;% px4_noGPS1_P.Gain7_Gain_a
                    section.data(293).logicalSrcIdx = 310;
                    section.data(293).dtTransOffset = 307;

                    ;% px4_noGPS1_P.Gain11_Gain
                    section.data(294).logicalSrcIdx = 311;
                    section.data(294).dtTransOffset = 308;

                    ;% px4_noGPS1_P.Gain9_Gain
                    section.data(295).logicalSrcIdx = 312;
                    section.data(295).dtTransOffset = 309;

                    ;% px4_noGPS1_P.DataStoreMemory10_InitialValue
                    section.data(296).logicalSrcIdx = 313;
                    section.data(296).dtTransOffset = 310;

                    ;% px4_noGPS1_P.DataStoreMemory11_InitialValue
                    section.data(297).logicalSrcIdx = 314;
                    section.data(297).dtTransOffset = 311;

                    ;% px4_noGPS1_P.DataStoreMemory12_InitialValue
                    section.data(298).logicalSrcIdx = 315;
                    section.data(298).dtTransOffset = 312;

                    ;% px4_noGPS1_P.DataStoreMemory13_InitialValue
                    section.data(299).logicalSrcIdx = 316;
                    section.data(299).dtTransOffset = 313;

                    ;% px4_noGPS1_P.DataStoreMemory14_InitialValue
                    section.data(300).logicalSrcIdx = 317;
                    section.data(300).dtTransOffset = 314;

                    ;% px4_noGPS1_P.DataStoreMemory15_InitialValue
                    section.data(301).logicalSrcIdx = 318;
                    section.data(301).dtTransOffset = 315;

                    ;% px4_noGPS1_P.DataStoreMemory16_InitialValue
                    section.data(302).logicalSrcIdx = 319;
                    section.data(302).dtTransOffset = 316;

                    ;% px4_noGPS1_P.DataStoreMemory17_InitialValue
                    section.data(303).logicalSrcIdx = 320;
                    section.data(303).dtTransOffset = 317;

                    ;% px4_noGPS1_P.DataStoreMemory18_InitialValue
                    section.data(304).logicalSrcIdx = 321;
                    section.data(304).dtTransOffset = 318;

                    ;% px4_noGPS1_P.DataStoreMemory19_InitialValue
                    section.data(305).logicalSrcIdx = 322;
                    section.data(305).dtTransOffset = 319;

                    ;% px4_noGPS1_P.DataStoreMemory2_InitialValue
                    section.data(306).logicalSrcIdx = 323;
                    section.data(306).dtTransOffset = 320;

                    ;% px4_noGPS1_P.DataStoreMemory20_InitialValue
                    section.data(307).logicalSrcIdx = 324;
                    section.data(307).dtTransOffset = 321;

                    ;% px4_noGPS1_P.DataStoreMemory21_InitialValue
                    section.data(308).logicalSrcIdx = 325;
                    section.data(308).dtTransOffset = 322;

                    ;% px4_noGPS1_P.DataStoreMemory22_InitialValue
                    section.data(309).logicalSrcIdx = 326;
                    section.data(309).dtTransOffset = 323;

                    ;% px4_noGPS1_P.DataStoreMemory23_InitialValue
                    section.data(310).logicalSrcIdx = 327;
                    section.data(310).dtTransOffset = 324;

                    ;% px4_noGPS1_P.DataStoreMemory24_InitialValue
                    section.data(311).logicalSrcIdx = 328;
                    section.data(311).dtTransOffset = 325;

                    ;% px4_noGPS1_P.DataStoreMemory25_InitialValue
                    section.data(312).logicalSrcIdx = 329;
                    section.data(312).dtTransOffset = 326;

                    ;% px4_noGPS1_P.DataStoreMemory26_InitialValue
                    section.data(313).logicalSrcIdx = 330;
                    section.data(313).dtTransOffset = 327;

                    ;% px4_noGPS1_P.DataStoreMemory28_InitialValue
                    section.data(314).logicalSrcIdx = 331;
                    section.data(314).dtTransOffset = 328;

                    ;% px4_noGPS1_P.DataStoreMemory29_InitialValue
                    section.data(315).logicalSrcIdx = 332;
                    section.data(315).dtTransOffset = 329;

                    ;% px4_noGPS1_P.DataStoreMemory3_InitialValue
                    section.data(316).logicalSrcIdx = 333;
                    section.data(316).dtTransOffset = 330;

                    ;% px4_noGPS1_P.DataStoreMemory31_InitialValue
                    section.data(317).logicalSrcIdx = 334;
                    section.data(317).dtTransOffset = 331;

                    ;% px4_noGPS1_P.DataStoreMemory32_InitialValue
                    section.data(318).logicalSrcIdx = 335;
                    section.data(318).dtTransOffset = 332;

                    ;% px4_noGPS1_P.DataStoreMemory36_InitialValue
                    section.data(319).logicalSrcIdx = 336;
                    section.data(319).dtTransOffset = 333;

                    ;% px4_noGPS1_P.DataStoreMemory4_InitialValue
                    section.data(320).logicalSrcIdx = 337;
                    section.data(320).dtTransOffset = 334;

                    ;% px4_noGPS1_P.DataStoreMemory6_InitialValue
                    section.data(321).logicalSrcIdx = 338;
                    section.data(321).dtTransOffset = 335;

                    ;% px4_noGPS1_P.DataStoreMemory7_InitialValue
                    section.data(322).logicalSrcIdx = 339;
                    section.data(322).dtTransOffset = 336;

                    ;% px4_noGPS1_P.DataStoreMemory8_InitialValue
                    section.data(323).logicalSrcIdx = 340;
                    section.data(323).dtTransOffset = 337;

                    ;% px4_noGPS1_P.DataStoreMemory9_InitialValue
                    section.data(324).logicalSrcIdx = 341;
                    section.data(324).dtTransOffset = 338;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% px4_noGPS1_P.Reset_Value
                    section.data(1).logicalSrcIdx = 342;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS1_P.attitude_flag_Value
                    section.data(2).logicalSrcIdx = 343;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS1_P.observer_flag_Value
                    section.data(3).logicalSrcIdx = 344;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS1_P.position_flag_Value
                    section.data(4).logicalSrcIdx = 345;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS1_P.Constant2_Value_kf
                    section.data(5).logicalSrcIdx = 346;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS1_P.DataStoreMemory_InitialValue_j
                    section.data(6).logicalSrcIdx = 347;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS1_P.DataStoreMemory1_InitialValue
                    section.data(7).logicalSrcIdx = 348;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS1_P.DataStoreMemory27_InitialValue
                    section.data(8).logicalSrcIdx = 349;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS1_P.DataStoreMemory30_InitialValue
                    section.data(9).logicalSrcIdx = 350;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS1_P.ManualSwitch_CurrentSetting
                    section.data(1).logicalSrcIdx = 351;
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
        ;% Auto data (px4_noGPS1_B)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS1_B.In1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS1_B.In1_a
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 46;
            section.data(46)  = dumData; %prealloc

                    ;% px4_noGPS1_B.Gain2
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS1_B.J
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS1_B.DataStoreRead4
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS1_B.DataStoreRead4_g
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS1_B.DataStoreRead4_b
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS1_B.rolldegree
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS1_B.rolldegree_l
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS1_B.rolldegree_c
                    section.data(8).logicalSrcIdx = 9;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS1_B.DataStore
                    section.data(9).logicalSrcIdx = 10;
                    section.data(9).dtTransOffset = 8;

                    ;% px4_noGPS1_B.Gain5
                    section.data(10).logicalSrcIdx = 11;
                    section.data(10).dtTransOffset = 9;

                    ;% px4_noGPS1_B.Gain3
                    section.data(11).logicalSrcIdx = 12;
                    section.data(11).dtTransOffset = 10;

                    ;% px4_noGPS1_B.DataStoreRead13
                    section.data(12).logicalSrcIdx = 13;
                    section.data(12).dtTransOffset = 11;

                    ;% px4_noGPS1_B.DataStoreRead15
                    section.data(13).logicalSrcIdx = 14;
                    section.data(13).dtTransOffset = 12;

                    ;% px4_noGPS1_B.DataStoreRead16
                    section.data(14).logicalSrcIdx = 15;
                    section.data(14).dtTransOffset = 13;

                    ;% px4_noGPS1_B.DataStoreRead17
                    section.data(15).logicalSrcIdx = 16;
                    section.data(15).dtTransOffset = 14;

                    ;% px4_noGPS1_B.DataStoreRead19
                    section.data(16).logicalSrcIdx = 17;
                    section.data(16).dtTransOffset = 15;

                    ;% px4_noGPS1_B.Gain6
                    section.data(17).logicalSrcIdx = 18;
                    section.data(17).dtTransOffset = 16;

                    ;% px4_noGPS1_B.DataStoreRead25
                    section.data(18).logicalSrcIdx = 19;
                    section.data(18).dtTransOffset = 17;

                    ;% px4_noGPS1_B.DataStoreRead26
                    section.data(19).logicalSrcIdx = 20;
                    section.data(19).dtTransOffset = 18;

                    ;% px4_noGPS1_B.DataStoreRead27
                    section.data(20).logicalSrcIdx = 21;
                    section.data(20).dtTransOffset = 19;

                    ;% px4_noGPS1_B.pitch_thrust
                    section.data(21).logicalSrcIdx = 22;
                    section.data(21).dtTransOffset = 20;

                    ;% px4_noGPS1_B.roll_thrust
                    section.data(22).logicalSrcIdx = 23;
                    section.data(22).dtTransOffset = 21;

                    ;% px4_noGPS1_B.yaw_thrust
                    section.data(23).logicalSrcIdx = 24;
                    section.data(23).dtTransOffset = 22;

                    ;% px4_noGPS1_B.DataStoreRead73
                    section.data(24).logicalSrcIdx = 25;
                    section.data(24).dtTransOffset = 23;

                    ;% px4_noGPS1_B.pitch
                    section.data(25).logicalSrcIdx = 26;
                    section.data(25).dtTransOffset = 24;

                    ;% px4_noGPS1_B.pitch_a
                    section.data(26).logicalSrcIdx = 27;
                    section.data(26).dtTransOffset = 25;

                    ;% px4_noGPS1_B.roll
                    section.data(27).logicalSrcIdx = 28;
                    section.data(27).dtTransOffset = 26;

                    ;% px4_noGPS1_B.pitch_g
                    section.data(28).logicalSrcIdx = 29;
                    section.data(28).dtTransOffset = 27;

                    ;% px4_noGPS1_B.yaw
                    section.data(29).logicalSrcIdx = 30;
                    section.data(29).dtTransOffset = 28;

                    ;% px4_noGPS1_B.DataStoreRead34
                    section.data(30).logicalSrcIdx = 31;
                    section.data(30).dtTransOffset = 29;

                    ;% px4_noGPS1_B.DataStoreRead35
                    section.data(31).logicalSrcIdx = 32;
                    section.data(31).dtTransOffset = 30;

                    ;% px4_noGPS1_B.DataStoreRead36
                    section.data(32).logicalSrcIdx = 33;
                    section.data(32).dtTransOffset = 31;

                    ;% px4_noGPS1_B.DataStoreRead37
                    section.data(33).logicalSrcIdx = 34;
                    section.data(33).dtTransOffset = 32;

                    ;% px4_noGPS1_B.DataStoreRead38
                    section.data(34).logicalSrcIdx = 35;
                    section.data(34).dtTransOffset = 33;

                    ;% px4_noGPS1_B.DataStoreRead39
                    section.data(35).logicalSrcIdx = 36;
                    section.data(35).dtTransOffset = 34;

                    ;% px4_noGPS1_B.DataStoreRead42
                    section.data(36).logicalSrcIdx = 37;
                    section.data(36).dtTransOffset = 35;

                    ;% px4_noGPS1_B.DataStoreRead43
                    section.data(37).logicalSrcIdx = 38;
                    section.data(37).dtTransOffset = 36;

                    ;% px4_noGPS1_B.DataStoreRead44
                    section.data(38).logicalSrcIdx = 39;
                    section.data(38).dtTransOffset = 37;

                    ;% px4_noGPS1_B.DataStoreRead48
                    section.data(39).logicalSrcIdx = 40;
                    section.data(39).dtTransOffset = 38;

                    ;% px4_noGPS1_B.DataStoreRead49
                    section.data(40).logicalSrcIdx = 41;
                    section.data(40).dtTransOffset = 39;

                    ;% px4_noGPS1_B.DataStoreRead55
                    section.data(41).logicalSrcIdx = 42;
                    section.data(41).dtTransOffset = 40;

                    ;% px4_noGPS1_B.DataStoreRead8
                    section.data(42).logicalSrcIdx = 43;
                    section.data(42).dtTransOffset = 41;

                    ;% px4_noGPS1_B.DataStoreRead9
                    section.data(43).logicalSrcIdx = 44;
                    section.data(43).dtTransOffset = 42;

                    ;% px4_noGPS1_B.y
                    section.data(44).logicalSrcIdx = 45;
                    section.data(44).dtTransOffset = 43;

                    ;% px4_noGPS1_B.y_o
                    section.data(45).logicalSrcIdx = 46;
                    section.data(45).dtTransOffset = 44;

                    ;% px4_noGPS1_B.y_j
                    section.data(46).logicalSrcIdx = 47;
                    section.data(46).dtTransOffset = 45;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS1_B.output
                    section.data(1).logicalSrcIdx = 48;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% px4_noGPS1_B.NOT
                    section.data(1).logicalSrcIdx = 49;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS1_B.DataStoreRead12
                    section.data(2).logicalSrcIdx = 50;
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
        ;% Auto data (px4_noGPS1_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px4_noGPS1_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% px4_noGPS1_DW.obj_n
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS1_DW.obj_l
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 48;
            section.data(48)  = dumData; %prealloc

                    ;% px4_noGPS1_DW.UD_DSTATE
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator3_DSTATE
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS1_DW.UD_DSTATE_b
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator3_DSTAT_a
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS1_DW.UD_DSTATE_n
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator3_DSTAT_m
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator1_DSTATE
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator_DSTATE_p
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator1_DSTAT_i
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 9;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator_DSTATE_f
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 10;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator1_DSTAT_g
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 11;

                    ;% px4_noGPS1_DW.Intgrt_dX_DSTATE
                    section.data(13).logicalSrcIdx = 15;
                    section.data(13).dtTransOffset = 12;

                    ;% px4_noGPS1_DW.Intgrt_dY_DSTATE
                    section.data(14).logicalSrcIdx = 16;
                    section.data(14).dtTransOffset = 13;

                    ;% px4_noGPS1_DW.Intgrt_ddY_DSTATE
                    section.data(15).logicalSrcIdx = 17;
                    section.data(15).dtTransOffset = 14;

                    ;% px4_noGPS1_DW.Intgrt_ddX_DSTATE
                    section.data(16).logicalSrcIdx = 18;
                    section.data(16).dtTransOffset = 15;

                    ;% px4_noGPS1_DW.UD_DSTATE_n2
                    section.data(17).logicalSrcIdx = 19;
                    section.data(17).dtTransOffset = 16;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator_DSTATE_d
                    section.data(18).logicalSrcIdx = 20;
                    section.data(18).dtTransOffset = 17;

                    ;% px4_noGPS1_DW.UD_DSTATE_m
                    section.data(19).logicalSrcIdx = 21;
                    section.data(19).dtTransOffset = 18;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator_DSTATE_i
                    section.data(20).logicalSrcIdx = 22;
                    section.data(20).dtTransOffset = 19;

                    ;% px4_noGPS1_DW.Intgrt_dZ_DSTATE
                    section.data(21).logicalSrcIdx = 23;
                    section.data(21).dtTransOffset = 20;

                    ;% px4_noGPS1_DW.Intgrt_ddZ_DSTATE
                    section.data(22).logicalSrcIdx = 24;
                    section.data(22).dtTransOffset = 21;

                    ;% px4_noGPS1_DW.DiscreteTimeIntegrator_DSTAT_fj
                    section.data(23).logicalSrcIdx = 25;
                    section.data(23).dtTransOffset = 22;

                    ;% px4_noGPS1_DW.start_time_yaw
                    section.data(24).logicalSrcIdx = 30;
                    section.data(24).dtTransOffset = 23;

                    ;% px4_noGPS1_DW.start_time
                    section.data(25).logicalSrcIdx = 31;
                    section.data(25).dtTransOffset = 24;

                    ;% px4_noGPS1_DW.start_time_roll
                    section.data(26).logicalSrcIdx = 32;
                    section.data(26).dtTransOffset = 25;

                    ;% px4_noGPS1_DW.e_pitch
                    section.data(27).logicalSrcIdx = 33;
                    section.data(27).dtTransOffset = 26;

                    ;% px4_noGPS1_DW.e_pitch_roll
                    section.data(28).logicalSrcIdx = 34;
                    section.data(28).dtTransOffset = 27;

                    ;% px4_noGPS1_DW.e_pitch_yaw
                    section.data(29).logicalSrcIdx = 35;
                    section.data(29).dtTransOffset = 28;

                    ;% px4_noGPS1_DW.yaw_speed
                    section.data(30).logicalSrcIdx = 42;
                    section.data(30).dtTransOffset = 29;

                    ;% px4_noGPS1_DW.roll_speed
                    section.data(31).logicalSrcIdx = 43;
                    section.data(31).dtTransOffset = 30;

                    ;% px4_noGPS1_DW.pitch_speed
                    section.data(32).logicalSrcIdx = 44;
                    section.data(32).dtTransOffset = 31;

                    ;% px4_noGPS1_DW.pitch_acc
                    section.data(33).logicalSrcIdx = 45;
                    section.data(33).dtTransOffset = 32;

                    ;% px4_noGPS1_DW.roll_acc
                    section.data(34).logicalSrcIdx = 47;
                    section.data(34).dtTransOffset = 33;

                    ;% px4_noGPS1_DW.yaw_acc
                    section.data(35).logicalSrcIdx = 48;
                    section.data(35).dtTransOffset = 34;

                    ;% px4_noGPS1_DW.roll_desire
                    section.data(36).logicalSrcIdx = 49;
                    section.data(36).dtTransOffset = 35;

                    ;% px4_noGPS1_DW.pitch_desire
                    section.data(37).logicalSrcIdx = 50;
                    section.data(37).dtTransOffset = 36;

                    ;% px4_noGPS1_DW.q_x
                    section.data(38).logicalSrcIdx = 51;
                    section.data(38).dtTransOffset = 37;

                    ;% px4_noGPS1_DW.q_y
                    section.data(39).logicalSrcIdx = 52;
                    section.data(39).dtTransOffset = 38;

                    ;% px4_noGPS1_DW.q_z
                    section.data(40).logicalSrcIdx = 53;
                    section.data(40).dtTransOffset = 39;

                    ;% px4_noGPS1_DW.lat
                    section.data(41).logicalSrcIdx = 54;
                    section.data(41).dtTransOffset = 40;

                    ;% px4_noGPS1_DW.t
                    section.data(42).logicalSrcIdx = 55;
                    section.data(42).dtTransOffset = 41;

                    ;% px4_noGPS1_DW.lon
                    section.data(43).logicalSrcIdx = 57;
                    section.data(43).dtTransOffset = 42;

                    ;% px4_noGPS1_DW.alt
                    section.data(44).logicalSrcIdx = 58;
                    section.data(44).dtTransOffset = 43;

                    ;% px4_noGPS1_DW.U1
                    section.data(45).logicalSrcIdx = 59;
                    section.data(45).dtTransOffset = 44;

                    ;% px4_noGPS1_DW.pitch
                    section.data(46).logicalSrcIdx = 60;
                    section.data(46).dtTransOffset = 45;

                    ;% px4_noGPS1_DW.roll
                    section.data(47).logicalSrcIdx = 61;
                    section.data(47).dtTransOffset = 46;

                    ;% px4_noGPS1_DW.yaw
                    section.data(48).logicalSrcIdx = 63;
                    section.data(48).dtTransOffset = 47;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% px4_noGPS1_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 65;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS1_DW.Scope_PWORK_o.LoggedData
                    section.data(2).logicalSrcIdx = 66;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS1_DW.Scope_PWORK_i.LoggedData
                    section.data(3).logicalSrcIdx = 67;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS1_DW.Scope_PWORK_ot.LoggedData
                    section.data(4).logicalSrcIdx = 68;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS1_DW.Scope_PWORK_f.LoggedData
                    section.data(5).logicalSrcIdx = 69;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS1_DW.Scope_PWORK_b.LoggedData
                    section.data(6).logicalSrcIdx = 70;
                    section.data(6).dtTransOffset = 6;

                    ;% px4_noGPS1_DW.Scope_PWORK_j.LoggedData
                    section.data(7).logicalSrcIdx = 71;
                    section.data(7).dtTransOffset = 7;

                    ;% px4_noGPS1_DW.Scope1_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 72;
                    section.data(8).dtTransOffset = 8;

                    ;% px4_noGPS1_DW.Scope_PWORK_m.LoggedData
                    section.data(9).logicalSrcIdx = 73;
                    section.data(9).dtTransOffset = 12;

                    ;% px4_noGPS1_DW.Scope2_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 74;
                    section.data(10).dtTransOffset = 15;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% px4_noGPS1_DW.Subsystem1_SubsysRanBC
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS1_DW.IfActionSubsystem2_SubsysRanBC
                    section.data(2).logicalSrcIdx = 76;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS1_DW.IfActionSubsystem1_SubsysRanBC
                    section.data(3).logicalSrcIdx = 77;
                    section.data(3).dtTransOffset = 2;

                    ;% px4_noGPS1_DW.IfActionSubsystem_SubsysRanBC
                    section.data(4).logicalSrcIdx = 78;
                    section.data(4).dtTransOffset = 3;

                    ;% px4_noGPS1_DW.EnabledSubsystem_SubsysRanBC
                    section.data(5).logicalSrcIdx = 79;
                    section.data(5).dtTransOffset = 4;

                    ;% px4_noGPS1_DW.EnabledSubsystem_SubsysRanBC_b
                    section.data(6).logicalSrcIdx = 80;
                    section.data(6).dtTransOffset = 5;

                    ;% px4_noGPS1_DW.Subsystem_SubsysRanBC
                    section.data(7).logicalSrcIdx = 81;
                    section.data(7).dtTransOffset = 6;

                    ;% px4_noGPS1_DW.Subsystem_SubsysRanBC_m
                    section.data(8).logicalSrcIdx = 82;
                    section.data(8).dtTransOffset = 7;

                    ;% px4_noGPS1_DW.Subsystem_SubsysRanBC_k
                    section.data(9).logicalSrcIdx = 83;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% px4_noGPS1_DW.attitude_flag
                    section.data(1).logicalSrcIdx = 84;
                    section.data(1).dtTransOffset = 0;

                    ;% px4_noGPS1_DW.position_flag
                    section.data(2).logicalSrcIdx = 86;
                    section.data(2).dtTransOffset = 1;

                    ;% px4_noGPS1_DW.observer_flag
                    section.data(3).logicalSrcIdx = 87;
                    section.data(3).dtTransOffset = 2;

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


    targMap.checksum0 = 1852215565;
    targMap.checksum1 = 1438748260;
    targMap.checksum2 = 3246631958;
    targMap.checksum3 = 802024555;

