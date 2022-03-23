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
        ;% Auto data (px42LoopCtrQGC20220313_P)
        ;%
            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_P.DiscreteDerivative1_ICPrevScale
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_P.DiscreteDerivative1_ICPrevSca_o
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% px42LoopCtrQGC20220313_P.DiscreteDerivative1_ICPrevSca_d
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% px42LoopCtrQGC20220313_P.CompareToConstant1_const
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% px42LoopCtrQGC20220313_P.CompareToConstant1_const_b
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% px42LoopCtrQGC20220313_P.CompareToConstant1_const_h
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% px42LoopCtrQGC20220313_P.CompareToConstant2_const
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% px42LoopCtrQGC20220313_P.CompareToConstant1_const_hq
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% px42LoopCtrQGC20220313_P.CompareToConstant2_const_o
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% px42LoopCtrQGC20220313_P.CompareToConstant1_const_p
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% px42LoopCtrQGC20220313_P.CompareToConstant2_const_a
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% px42LoopCtrQGC20220313_P.CompareToConstant1_const_a
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_P.Out1_Y0
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_P.Constant_Value
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_P.Out1_Y0_k
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_P.Constant_Value_c
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 283;
            section.data(283)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_P.Constant1_Value
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_P.Constant1_Value_n
                    section.data(2).logicalSrcIdx = 17;
                    section.data(2).dtTransOffset = 1;

                    ;% px42LoopCtrQGC20220313_P.Constant1_Value_a
                    section.data(3).logicalSrcIdx = 18;
                    section.data(3).dtTransOffset = 2;

                    ;% px42LoopCtrQGC20220313_P.Saturation_UpperSat
                    section.data(4).logicalSrcIdx = 19;
                    section.data(4).dtTransOffset = 3;

                    ;% px42LoopCtrQGC20220313_P.Saturation_LowerSat
                    section.data(5).logicalSrcIdx = 20;
                    section.data(5).dtTransOffset = 4;

                    ;% px42LoopCtrQGC20220313_P.Constant_Value_b
                    section.data(6).logicalSrcIdx = 21;
                    section.data(6).dtTransOffset = 5;

                    ;% px42LoopCtrQGC20220313_P.Constant3_Value
                    section.data(7).logicalSrcIdx = 22;
                    section.data(7).dtTransOffset = 6;

                    ;% px42LoopCtrQGC20220313_P.Constant3_Value_a
                    section.data(8).logicalSrcIdx = 23;
                    section.data(8).dtTransOffset = 7;

                    ;% px42LoopCtrQGC20220313_P.Constant3_Value_d
                    section.data(9).logicalSrcIdx = 24;
                    section.data(9).dtTransOffset = 8;

                    ;% px42LoopCtrQGC20220313_P.Constant_Value_e
                    section.data(10).logicalSrcIdx = 25;
                    section.data(10).dtTransOffset = 9;

                    ;% px42LoopCtrQGC20220313_P.Constant_Value_b1
                    section.data(11).logicalSrcIdx = 26;
                    section.data(11).dtTransOffset = 10;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_gainval
                    section.data(12).logicalSrcIdx = 27;
                    section.data(12).dtTransOffset = 11;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_IC
                    section.data(13).logicalSrcIdx = 28;
                    section.data(13).dtTransOffset = 12;

                    ;% px42LoopCtrQGC20220313_P.Constant9_Value
                    section.data(14).logicalSrcIdx = 29;
                    section.data(14).dtTransOffset = 13;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory22_InitialValue
                    section.data(15).logicalSrcIdx = 30;
                    section.data(15).dtTransOffset = 14;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory23_InitialValue
                    section.data(16).logicalSrcIdx = 31;
                    section.data(16).dtTransOffset = 15;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory24_InitialValue
                    section.data(17).logicalSrcIdx = 32;
                    section.data(17).dtTransOffset = 16;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory25_InitialValue
                    section.data(18).logicalSrcIdx = 33;
                    section.data(18).dtTransOffset = 17;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory26_InitialValue
                    section.data(19).logicalSrcIdx = 34;
                    section.data(19).dtTransOffset = 18;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory5_InitialValue
                    section.data(20).logicalSrcIdx = 35;
                    section.data(20).dtTransOffset = 19;

                    ;% px42LoopCtrQGC20220313_P.Constant3_Value_g
                    section.data(21).logicalSrcIdx = 36;
                    section.data(21).dtTransOffset = 20;

                    ;% px42LoopCtrQGC20220313_P.r_Value
                    section.data(22).logicalSrcIdx = 37;
                    section.data(22).dtTransOffset = 21;

                    ;% px42LoopCtrQGC20220313_P.ch_Value
                    section.data(23).logicalSrcIdx = 38;
                    section.data(23).dtTransOffset = 22;

                    ;% px42LoopCtrQGC20220313_P.T_Value
                    section.data(24).logicalSrcIdx = 39;
                    section.data(24).dtTransOffset = 23;

                    ;% px42LoopCtrQGC20220313_P.t_Value
                    section.data(25).logicalSrcIdx = 40;
                    section.data(25).dtTransOffset = 24;

                    ;% px42LoopCtrQGC20220313_P.b_Value
                    section.data(26).logicalSrcIdx = 41;
                    section.data(26).dtTransOffset = 25;

                    ;% px42LoopCtrQGC20220313_P.Gain4_Gain
                    section.data(27).logicalSrcIdx = 42;
                    section.data(27).dtTransOffset = 26;

                    ;% px42LoopCtrQGC20220313_P.TSamp_WtEt
                    section.data(28).logicalSrcIdx = 43;
                    section.data(28).dtTransOffset = 27;

                    ;% px42LoopCtrQGC20220313_P.l_Value
                    section.data(29).logicalSrcIdx = 44;
                    section.data(29).dtTransOffset = 28;

                    ;% px42LoopCtrQGC20220313_P.Gain_Gain
                    section.data(30).logicalSrcIdx = 45;
                    section.data(30).dtTransOffset = 29;

                    ;% px42LoopCtrQGC20220313_P.Gain1_Gain
                    section.data(31).logicalSrcIdx = 46;
                    section.data(31).dtTransOffset = 30;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_gainval
                    section.data(32).logicalSrcIdx = 47;
                    section.data(32).dtTransOffset = 31;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_IC
                    section.data(33).logicalSrcIdx = 48;
                    section.data(33).dtTransOffset = 32;

                    ;% px42LoopCtrQGC20220313_P.Gain1_Gain_o
                    section.data(34).logicalSrcIdx = 49;
                    section.data(34).dtTransOffset = 33;

                    ;% px42LoopCtrQGC20220313_P.Saturation4_UpperSat
                    section.data(35).logicalSrcIdx = 50;
                    section.data(35).dtTransOffset = 34;

                    ;% px42LoopCtrQGC20220313_P.Saturation4_LowerSat
                    section.data(36).logicalSrcIdx = 51;
                    section.data(36).dtTransOffset = 35;

                    ;% px42LoopCtrQGC20220313_P.SineWave_Amp
                    section.data(37).logicalSrcIdx = 52;
                    section.data(37).dtTransOffset = 36;

                    ;% px42LoopCtrQGC20220313_P.SineWave_Bias
                    section.data(38).logicalSrcIdx = 53;
                    section.data(38).dtTransOffset = 37;

                    ;% px42LoopCtrQGC20220313_P.SineWave_Freq
                    section.data(39).logicalSrcIdx = 54;
                    section.data(39).dtTransOffset = 38;

                    ;% px42LoopCtrQGC20220313_P.SineWave_Hsin
                    section.data(40).logicalSrcIdx = 55;
                    section.data(40).dtTransOffset = 39;

                    ;% px42LoopCtrQGC20220313_P.SineWave_HCos
                    section.data(41).logicalSrcIdx = 56;
                    section.data(41).dtTransOffset = 40;

                    ;% px42LoopCtrQGC20220313_P.SineWave_PSin
                    section.data(42).logicalSrcIdx = 57;
                    section.data(42).dtTransOffset = 41;

                    ;% px42LoopCtrQGC20220313_P.SineWave_PCos
                    section.data(43).logicalSrcIdx = 58;
                    section.data(43).dtTransOffset = 42;

                    ;% px42LoopCtrQGC20220313_P.r_Value_g
                    section.data(44).logicalSrcIdx = 59;
                    section.data(44).dtTransOffset = 43;

                    ;% px42LoopCtrQGC20220313_P.ch_Value_j
                    section.data(45).logicalSrcIdx = 60;
                    section.data(45).dtTransOffset = 44;

                    ;% px42LoopCtrQGC20220313_P.T_Value_p
                    section.data(46).logicalSrcIdx = 61;
                    section.data(46).dtTransOffset = 45;

                    ;% px42LoopCtrQGC20220313_P.t_Value_n
                    section.data(47).logicalSrcIdx = 62;
                    section.data(47).dtTransOffset = 46;

                    ;% px42LoopCtrQGC20220313_P.b_Value_l
                    section.data(48).logicalSrcIdx = 63;
                    section.data(48).dtTransOffset = 47;

                    ;% px42LoopCtrQGC20220313_P.Gain4_Gain_b
                    section.data(49).logicalSrcIdx = 64;
                    section.data(49).dtTransOffset = 48;

                    ;% px42LoopCtrQGC20220313_P.TSamp_WtEt_p
                    section.data(50).logicalSrcIdx = 65;
                    section.data(50).dtTransOffset = 49;

                    ;% px42LoopCtrQGC20220313_P.l_Value_b
                    section.data(51).logicalSrcIdx = 66;
                    section.data(51).dtTransOffset = 50;

                    ;% px42LoopCtrQGC20220313_P.Gain_Gain_o
                    section.data(52).logicalSrcIdx = 67;
                    section.data(52).dtTransOffset = 51;

                    ;% px42LoopCtrQGC20220313_P.Gain1_Gain_b
                    section.data(53).logicalSrcIdx = 68;
                    section.data(53).dtTransOffset = 52;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_gainv_m
                    section.data(54).logicalSrcIdx = 69;
                    section.data(54).dtTransOffset = 53;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_IC_k
                    section.data(55).logicalSrcIdx = 70;
                    section.data(55).dtTransOffset = 54;

                    ;% px42LoopCtrQGC20220313_P.Gain2_Gain
                    section.data(56).logicalSrcIdx = 71;
                    section.data(56).dtTransOffset = 55;

                    ;% px42LoopCtrQGC20220313_P.r_Value_p
                    section.data(57).logicalSrcIdx = 72;
                    section.data(57).dtTransOffset = 56;

                    ;% px42LoopCtrQGC20220313_P.ch_Value_e
                    section.data(58).logicalSrcIdx = 73;
                    section.data(58).dtTransOffset = 57;

                    ;% px42LoopCtrQGC20220313_P.T_Value_c
                    section.data(59).logicalSrcIdx = 74;
                    section.data(59).dtTransOffset = 58;

                    ;% px42LoopCtrQGC20220313_P.t_Value_m
                    section.data(60).logicalSrcIdx = 75;
                    section.data(60).dtTransOffset = 59;

                    ;% px42LoopCtrQGC20220313_P.b_Value_h
                    section.data(61).logicalSrcIdx = 76;
                    section.data(61).dtTransOffset = 60;

                    ;% px42LoopCtrQGC20220313_P.Gain4_Gain_o
                    section.data(62).logicalSrcIdx = 77;
                    section.data(62).dtTransOffset = 61;

                    ;% px42LoopCtrQGC20220313_P.TSamp_WtEt_o
                    section.data(63).logicalSrcIdx = 78;
                    section.data(63).dtTransOffset = 62;

                    ;% px42LoopCtrQGC20220313_P.l_Value_n
                    section.data(64).logicalSrcIdx = 79;
                    section.data(64).dtTransOffset = 63;

                    ;% px42LoopCtrQGC20220313_P.Gain_Gain_m
                    section.data(65).logicalSrcIdx = 80;
                    section.data(65).dtTransOffset = 64;

                    ;% px42LoopCtrQGC20220313_P.J_Gain
                    section.data(66).logicalSrcIdx = 81;
                    section.data(66).dtTransOffset = 65;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_gainv_e
                    section.data(67).logicalSrcIdx = 82;
                    section.data(67).dtTransOffset = 66;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator3_IC_l
                    section.data(68).logicalSrcIdx = 83;
                    section.data(68).dtTransOffset = 67;

                    ;% px42LoopCtrQGC20220313_P.J_Gain_b
                    section.data(69).logicalSrcIdx = 84;
                    section.data(69).dtTransOffset = 68;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory_InitialValue
                    section.data(70).logicalSrcIdx = 85;
                    section.data(70).dtTransOffset = 69;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory_InitialValue_l
                    section.data(71).logicalSrcIdx = 86;
                    section.data(71).dtTransOffset = 70;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory_InitialValue_b
                    section.data(72).logicalSrcIdx = 87;
                    section.data(72).dtTransOffset = 71;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_gainva_n
                    section.data(73).logicalSrcIdx = 88;
                    section.data(73).dtTransOffset = 72;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_IC_l
                    section.data(74).logicalSrcIdx = 89;
                    section.data(74).dtTransOffset = 73;

                    ;% px42LoopCtrQGC20220313_P.Gain2_Gain_c
                    section.data(75).logicalSrcIdx = 90;
                    section.data(75).dtTransOffset = 74;

                    ;% px42LoopCtrQGC20220313_P.uJ_Gain
                    section.data(76).logicalSrcIdx = 91;
                    section.data(76).dtTransOffset = 75;

                    ;% px42LoopCtrQGC20220313_P.kJ_Gain
                    section.data(77).logicalSrcIdx = 92;
                    section.data(77).dtTransOffset = 76;

                    ;% px42LoopCtrQGC20220313_P.Saturation_UpperSat_b
                    section.data(78).logicalSrcIdx = 93;
                    section.data(78).dtTransOffset = 77;

                    ;% px42LoopCtrQGC20220313_P.Saturation_LowerSat_k
                    section.data(79).logicalSrcIdx = 94;
                    section.data(79).dtTransOffset = 78;

                    ;% px42LoopCtrQGC20220313_P.l1_Gain
                    section.data(80).logicalSrcIdx = 95;
                    section.data(80).dtTransOffset = 79;

                    ;% px42LoopCtrQGC20220313_P.lambda1_Gain
                    section.data(81).logicalSrcIdx = 96;
                    section.data(81).dtTransOffset = 80;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_gainval
                    section.data(82).logicalSrcIdx = 97;
                    section.data(82).dtTransOffset = 81;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_IC
                    section.data(83).logicalSrcIdx = 98;
                    section.data(83).dtTransOffset = 82;

                    ;% px42LoopCtrQGC20220313_P.Constant1_Value_f
                    section.data(84).logicalSrcIdx = 99;
                    section.data(84).dtTransOffset = 83;

                    ;% px42LoopCtrQGC20220313_P.Saturation10_UpperSat
                    section.data(85).logicalSrcIdx = 100;
                    section.data(85).dtTransOffset = 84;

                    ;% px42LoopCtrQGC20220313_P.Saturation10_LowerSat
                    section.data(86).logicalSrcIdx = 101;
                    section.data(86).dtTransOffset = 85;

                    ;% px42LoopCtrQGC20220313_P.Saturation11_UpperSat
                    section.data(87).logicalSrcIdx = 102;
                    section.data(87).dtTransOffset = 86;

                    ;% px42LoopCtrQGC20220313_P.Saturation11_LowerSat
                    section.data(88).logicalSrcIdx = 103;
                    section.data(88).dtTransOffset = 87;

                    ;% px42LoopCtrQGC20220313_P.Gain_Gain_ml
                    section.data(89).logicalSrcIdx = 104;
                    section.data(89).dtTransOffset = 88;

                    ;% px42LoopCtrQGC20220313_P.Saturation8_UpperSat
                    section.data(90).logicalSrcIdx = 105;
                    section.data(90).dtTransOffset = 89;

                    ;% px42LoopCtrQGC20220313_P.Saturation8_LowerSat
                    section.data(91).logicalSrcIdx = 106;
                    section.data(91).dtTransOffset = 90;

                    ;% px42LoopCtrQGC20220313_P.Constant2_Value
                    section.data(92).logicalSrcIdx = 107;
                    section.data(92).dtTransOffset = 91;

                    ;% px42LoopCtrQGC20220313_P.Gain5_Gain
                    section.data(93).logicalSrcIdx = 108;
                    section.data(93).dtTransOffset = 92;

                    ;% px42LoopCtrQGC20220313_P.Saturation13_UpperSat
                    section.data(94).logicalSrcIdx = 109;
                    section.data(94).dtTransOffset = 93;

                    ;% px42LoopCtrQGC20220313_P.Saturation13_LowerSat
                    section.data(95).logicalSrcIdx = 110;
                    section.data(95).dtTransOffset = 94;

                    ;% px42LoopCtrQGC20220313_P.Saturation9_UpperSat
                    section.data(96).logicalSrcIdx = 111;
                    section.data(96).dtTransOffset = 95;

                    ;% px42LoopCtrQGC20220313_P.Saturation9_LowerSat
                    section.data(97).logicalSrcIdx = 112;
                    section.data(97).dtTransOffset = 96;

                    ;% px42LoopCtrQGC20220313_P.Gain1_Gain_a
                    section.data(98).logicalSrcIdx = 113;
                    section.data(98).dtTransOffset = 97;

                    ;% px42LoopCtrQGC20220313_P.Constant4_Value
                    section.data(99).logicalSrcIdx = 114;
                    section.data(99).dtTransOffset = 98;

                    ;% px42LoopCtrQGC20220313_P.Saturation12_UpperSat
                    section.data(100).logicalSrcIdx = 115;
                    section.data(100).dtTransOffset = 99;

                    ;% px42LoopCtrQGC20220313_P.Saturation12_LowerSat
                    section.data(101).logicalSrcIdx = 116;
                    section.data(101).dtTransOffset = 100;

                    ;% px42LoopCtrQGC20220313_P.Saturation16_UpperSat
                    section.data(102).logicalSrcIdx = 117;
                    section.data(102).dtTransOffset = 101;

                    ;% px42LoopCtrQGC20220313_P.Saturation16_LowerSat
                    section.data(103).logicalSrcIdx = 118;
                    section.data(103).dtTransOffset = 102;

                    ;% px42LoopCtrQGC20220313_P.Saturation14_UpperSat
                    section.data(104).logicalSrcIdx = 119;
                    section.data(104).dtTransOffset = 103;

                    ;% px42LoopCtrQGC20220313_P.Saturation14_LowerSat
                    section.data(105).logicalSrcIdx = 120;
                    section.data(105).dtTransOffset = 104;

                    ;% px42LoopCtrQGC20220313_P.Gain3_Gain
                    section.data(106).logicalSrcIdx = 121;
                    section.data(106).dtTransOffset = 105;

                    ;% px42LoopCtrQGC20220313_P.Constant6_Value
                    section.data(107).logicalSrcIdx = 122;
                    section.data(107).dtTransOffset = 106;

                    ;% px42LoopCtrQGC20220313_P.lambda2_Gain
                    section.data(108).logicalSrcIdx = 123;
                    section.data(108).dtTransOffset = 107;

                    ;% px42LoopCtrQGC20220313_P.Saturation1_UpperSat
                    section.data(109).logicalSrcIdx = 124;
                    section.data(109).dtTransOffset = 108;

                    ;% px42LoopCtrQGC20220313_P.Saturation1_LowerSat
                    section.data(110).logicalSrcIdx = 125;
                    section.data(110).dtTransOffset = 109;

                    ;% px42LoopCtrQGC20220313_P.l2_Gain
                    section.data(111).logicalSrcIdx = 126;
                    section.data(111).dtTransOffset = 110;

                    ;% px42LoopCtrQGC20220313_P.Saturation15_UpperSat
                    section.data(112).logicalSrcIdx = 127;
                    section.data(112).dtTransOffset = 111;

                    ;% px42LoopCtrQGC20220313_P.Saturation15_LowerSat
                    section.data(113).logicalSrcIdx = 128;
                    section.data(113).dtTransOffset = 112;

                    ;% px42LoopCtrQGC20220313_P.Gain6_Gain
                    section.data(114).logicalSrcIdx = 129;
                    section.data(114).dtTransOffset = 113;

                    ;% px42LoopCtrQGC20220313_P.Saturation19_UpperSat
                    section.data(115).logicalSrcIdx = 130;
                    section.data(115).dtTransOffset = 114;

                    ;% px42LoopCtrQGC20220313_P.Saturation19_LowerSat
                    section.data(116).logicalSrcIdx = 131;
                    section.data(116).dtTransOffset = 115;

                    ;% px42LoopCtrQGC20220313_P.Saturation17_UpperSat
                    section.data(117).logicalSrcIdx = 132;
                    section.data(117).dtTransOffset = 116;

                    ;% px42LoopCtrQGC20220313_P.Saturation17_LowerSat
                    section.data(118).logicalSrcIdx = 133;
                    section.data(118).dtTransOffset = 117;

                    ;% px42LoopCtrQGC20220313_P.Gain4_Gain_f
                    section.data(119).logicalSrcIdx = 134;
                    section.data(119).dtTransOffset = 118;

                    ;% px42LoopCtrQGC20220313_P.Constant8_Value
                    section.data(120).logicalSrcIdx = 135;
                    section.data(120).dtTransOffset = 119;

                    ;% px42LoopCtrQGC20220313_P.Saturation18_UpperSat
                    section.data(121).logicalSrcIdx = 136;
                    section.data(121).dtTransOffset = 120;

                    ;% px42LoopCtrQGC20220313_P.Saturation18_LowerSat
                    section.data(122).logicalSrcIdx = 137;
                    section.data(122).dtTransOffset = 121;

                    ;% px42LoopCtrQGC20220313_P.Saturation3_UpperSat
                    section.data(123).logicalSrcIdx = 138;
                    section.data(123).dtTransOffset = 122;

                    ;% px42LoopCtrQGC20220313_P.Saturation3_LowerSat
                    section.data(124).logicalSrcIdx = 139;
                    section.data(124).dtTransOffset = 123;

                    ;% px42LoopCtrQGC20220313_P.l4_Gain
                    section.data(125).logicalSrcIdx = 140;
                    section.data(125).dtTransOffset = 124;

                    ;% px42LoopCtrQGC20220313_P.lambda4_Gain
                    section.data(126).logicalSrcIdx = 141;
                    section.data(126).dtTransOffset = 125;

                    ;% px42LoopCtrQGC20220313_P.Gain7_Gain
                    section.data(127).logicalSrcIdx = 142;
                    section.data(127).dtTransOffset = 126;

                    ;% px42LoopCtrQGC20220313_P.Gain8_Gain
                    section.data(128).logicalSrcIdx = 143;
                    section.data(128).dtTransOffset = 127;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_gainva_e
                    section.data(129).logicalSrcIdx = 144;
                    section.data(129).dtTransOffset = 128;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_IC_h
                    section.data(130).logicalSrcIdx = 145;
                    section.data(130).dtTransOffset = 129;

                    ;% px42LoopCtrQGC20220313_P.Gain2_Gain_g
                    section.data(131).logicalSrcIdx = 146;
                    section.data(131).dtTransOffset = 130;

                    ;% px42LoopCtrQGC20220313_P.uJ_Gain_p
                    section.data(132).logicalSrcIdx = 147;
                    section.data(132).dtTransOffset = 131;

                    ;% px42LoopCtrQGC20220313_P.kJ_Gain_c
                    section.data(133).logicalSrcIdx = 148;
                    section.data(133).dtTransOffset = 132;

                    ;% px42LoopCtrQGC20220313_P.Saturation_UpperSat_n
                    section.data(134).logicalSrcIdx = 149;
                    section.data(134).dtTransOffset = 133;

                    ;% px42LoopCtrQGC20220313_P.Saturation_LowerSat_g
                    section.data(135).logicalSrcIdx = 150;
                    section.data(135).dtTransOffset = 134;

                    ;% px42LoopCtrQGC20220313_P.l1_Gain_p
                    section.data(136).logicalSrcIdx = 151;
                    section.data(136).dtTransOffset = 135;

                    ;% px42LoopCtrQGC20220313_P.lambda1_Gain_a
                    section.data(137).logicalSrcIdx = 152;
                    section.data(137).dtTransOffset = 136;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_gainv_n
                    section.data(138).logicalSrcIdx = 153;
                    section.data(138).dtTransOffset = 137;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_IC_j
                    section.data(139).logicalSrcIdx = 154;
                    section.data(139).dtTransOffset = 138;

                    ;% px42LoopCtrQGC20220313_P.Constant1_Value_j
                    section.data(140).logicalSrcIdx = 155;
                    section.data(140).dtTransOffset = 139;

                    ;% px42LoopCtrQGC20220313_P.Saturation10_UpperSat_o
                    section.data(141).logicalSrcIdx = 156;
                    section.data(141).dtTransOffset = 140;

                    ;% px42LoopCtrQGC20220313_P.Saturation10_LowerSat_b
                    section.data(142).logicalSrcIdx = 157;
                    section.data(142).dtTransOffset = 141;

                    ;% px42LoopCtrQGC20220313_P.Saturation11_UpperSat_p
                    section.data(143).logicalSrcIdx = 158;
                    section.data(143).dtTransOffset = 142;

                    ;% px42LoopCtrQGC20220313_P.Saturation11_LowerSat_i
                    section.data(144).logicalSrcIdx = 159;
                    section.data(144).dtTransOffset = 143;

                    ;% px42LoopCtrQGC20220313_P.Gain_Gain_g
                    section.data(145).logicalSrcIdx = 160;
                    section.data(145).dtTransOffset = 144;

                    ;% px42LoopCtrQGC20220313_P.Saturation8_UpperSat_g
                    section.data(146).logicalSrcIdx = 161;
                    section.data(146).dtTransOffset = 145;

                    ;% px42LoopCtrQGC20220313_P.Saturation8_LowerSat_g
                    section.data(147).logicalSrcIdx = 162;
                    section.data(147).dtTransOffset = 146;

                    ;% px42LoopCtrQGC20220313_P.Constant2_Value_h
                    section.data(148).logicalSrcIdx = 163;
                    section.data(148).dtTransOffset = 147;

                    ;% px42LoopCtrQGC20220313_P.Gain5_Gain_o
                    section.data(149).logicalSrcIdx = 164;
                    section.data(149).dtTransOffset = 148;

                    ;% px42LoopCtrQGC20220313_P.Saturation13_UpperSat_i
                    section.data(150).logicalSrcIdx = 165;
                    section.data(150).dtTransOffset = 149;

                    ;% px42LoopCtrQGC20220313_P.Saturation13_LowerSat_c
                    section.data(151).logicalSrcIdx = 166;
                    section.data(151).dtTransOffset = 150;

                    ;% px42LoopCtrQGC20220313_P.Saturation9_UpperSat_i
                    section.data(152).logicalSrcIdx = 167;
                    section.data(152).dtTransOffset = 151;

                    ;% px42LoopCtrQGC20220313_P.Saturation9_LowerSat_c
                    section.data(153).logicalSrcIdx = 168;
                    section.data(153).dtTransOffset = 152;

                    ;% px42LoopCtrQGC20220313_P.Gain1_Gain_d
                    section.data(154).logicalSrcIdx = 169;
                    section.data(154).dtTransOffset = 153;

                    ;% px42LoopCtrQGC20220313_P.Constant4_Value_n
                    section.data(155).logicalSrcIdx = 170;
                    section.data(155).dtTransOffset = 154;

                    ;% px42LoopCtrQGC20220313_P.Saturation12_UpperSat_c
                    section.data(156).logicalSrcIdx = 171;
                    section.data(156).dtTransOffset = 155;

                    ;% px42LoopCtrQGC20220313_P.Saturation12_LowerSat_b
                    section.data(157).logicalSrcIdx = 172;
                    section.data(157).dtTransOffset = 156;

                    ;% px42LoopCtrQGC20220313_P.Saturation16_UpperSat_l
                    section.data(158).logicalSrcIdx = 173;
                    section.data(158).dtTransOffset = 157;

                    ;% px42LoopCtrQGC20220313_P.Saturation16_LowerSat_g
                    section.data(159).logicalSrcIdx = 174;
                    section.data(159).dtTransOffset = 158;

                    ;% px42LoopCtrQGC20220313_P.Saturation14_UpperSat_l
                    section.data(160).logicalSrcIdx = 175;
                    section.data(160).dtTransOffset = 159;

                    ;% px42LoopCtrQGC20220313_P.Saturation14_LowerSat_b
                    section.data(161).logicalSrcIdx = 176;
                    section.data(161).dtTransOffset = 160;

                    ;% px42LoopCtrQGC20220313_P.Gain3_Gain_l
                    section.data(162).logicalSrcIdx = 177;
                    section.data(162).dtTransOffset = 161;

                    ;% px42LoopCtrQGC20220313_P.Constant6_Value_o
                    section.data(163).logicalSrcIdx = 178;
                    section.data(163).dtTransOffset = 162;

                    ;% px42LoopCtrQGC20220313_P.lambda2_Gain_j
                    section.data(164).logicalSrcIdx = 179;
                    section.data(164).dtTransOffset = 163;

                    ;% px42LoopCtrQGC20220313_P.Saturation1_UpperSat_a
                    section.data(165).logicalSrcIdx = 180;
                    section.data(165).dtTransOffset = 164;

                    ;% px42LoopCtrQGC20220313_P.Saturation1_LowerSat_i
                    section.data(166).logicalSrcIdx = 181;
                    section.data(166).dtTransOffset = 165;

                    ;% px42LoopCtrQGC20220313_P.l2_Gain_l
                    section.data(167).logicalSrcIdx = 182;
                    section.data(167).dtTransOffset = 166;

                    ;% px42LoopCtrQGC20220313_P.Saturation15_UpperSat_j
                    section.data(168).logicalSrcIdx = 183;
                    section.data(168).dtTransOffset = 167;

                    ;% px42LoopCtrQGC20220313_P.Saturation15_LowerSat_k
                    section.data(169).logicalSrcIdx = 184;
                    section.data(169).dtTransOffset = 168;

                    ;% px42LoopCtrQGC20220313_P.Gain6_Gain_e
                    section.data(170).logicalSrcIdx = 185;
                    section.data(170).dtTransOffset = 169;

                    ;% px42LoopCtrQGC20220313_P.Saturation19_UpperSat_b
                    section.data(171).logicalSrcIdx = 186;
                    section.data(171).dtTransOffset = 170;

                    ;% px42LoopCtrQGC20220313_P.Saturation19_LowerSat_j
                    section.data(172).logicalSrcIdx = 187;
                    section.data(172).dtTransOffset = 171;

                    ;% px42LoopCtrQGC20220313_P.Saturation17_UpperSat_d
                    section.data(173).logicalSrcIdx = 188;
                    section.data(173).dtTransOffset = 172;

                    ;% px42LoopCtrQGC20220313_P.Saturation17_LowerSat_o
                    section.data(174).logicalSrcIdx = 189;
                    section.data(174).dtTransOffset = 173;

                    ;% px42LoopCtrQGC20220313_P.Gain4_Gain_n
                    section.data(175).logicalSrcIdx = 190;
                    section.data(175).dtTransOffset = 174;

                    ;% px42LoopCtrQGC20220313_P.Constant8_Value_f
                    section.data(176).logicalSrcIdx = 191;
                    section.data(176).dtTransOffset = 175;

                    ;% px42LoopCtrQGC20220313_P.Saturation18_UpperSat_a
                    section.data(177).logicalSrcIdx = 192;
                    section.data(177).dtTransOffset = 176;

                    ;% px42LoopCtrQGC20220313_P.Saturation18_LowerSat_h
                    section.data(178).logicalSrcIdx = 193;
                    section.data(178).dtTransOffset = 177;

                    ;% px42LoopCtrQGC20220313_P.Saturation3_UpperSat_m
                    section.data(179).logicalSrcIdx = 194;
                    section.data(179).dtTransOffset = 178;

                    ;% px42LoopCtrQGC20220313_P.Saturation3_LowerSat_i
                    section.data(180).logicalSrcIdx = 195;
                    section.data(180).dtTransOffset = 179;

                    ;% px42LoopCtrQGC20220313_P.l4_Gain_p
                    section.data(181).logicalSrcIdx = 196;
                    section.data(181).dtTransOffset = 180;

                    ;% px42LoopCtrQGC20220313_P.lambda4_Gain_a
                    section.data(182).logicalSrcIdx = 197;
                    section.data(182).dtTransOffset = 181;

                    ;% px42LoopCtrQGC20220313_P.Gain7_Gain_d
                    section.data(183).logicalSrcIdx = 198;
                    section.data(183).dtTransOffset = 182;

                    ;% px42LoopCtrQGC20220313_P.Gain8_Gain_b
                    section.data(184).logicalSrcIdx = 199;
                    section.data(184).dtTransOffset = 183;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_gainv_nv
                    section.data(185).logicalSrcIdx = 200;
                    section.data(185).dtTransOffset = 184;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator_IC_o
                    section.data(186).logicalSrcIdx = 201;
                    section.data(186).dtTransOffset = 185;

                    ;% px42LoopCtrQGC20220313_P.Gain2_Gain_p
                    section.data(187).logicalSrcIdx = 202;
                    section.data(187).dtTransOffset = 186;

                    ;% px42LoopCtrQGC20220313_P.uJ_Gain_g
                    section.data(188).logicalSrcIdx = 203;
                    section.data(188).dtTransOffset = 187;

                    ;% px42LoopCtrQGC20220313_P.kJ_Gain_p
                    section.data(189).logicalSrcIdx = 204;
                    section.data(189).dtTransOffset = 188;

                    ;% px42LoopCtrQGC20220313_P.Saturation_UpperSat_n1
                    section.data(190).logicalSrcIdx = 205;
                    section.data(190).dtTransOffset = 189;

                    ;% px42LoopCtrQGC20220313_P.Saturation_LowerSat_c
                    section.data(191).logicalSrcIdx = 206;
                    section.data(191).dtTransOffset = 190;

                    ;% px42LoopCtrQGC20220313_P.l1_Gain_d
                    section.data(192).logicalSrcIdx = 207;
                    section.data(192).dtTransOffset = 191;

                    ;% px42LoopCtrQGC20220313_P.lambda1_Gain_g
                    section.data(193).logicalSrcIdx = 208;
                    section.data(193).dtTransOffset = 192;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_gainv_g
                    section.data(194).logicalSrcIdx = 209;
                    section.data(194).dtTransOffset = 193;

                    ;% px42LoopCtrQGC20220313_P.DiscreteTimeIntegrator1_IC_c
                    section.data(195).logicalSrcIdx = 210;
                    section.data(195).dtTransOffset = 194;

                    ;% px42LoopCtrQGC20220313_P.Constant1_Value_ac
                    section.data(196).logicalSrcIdx = 211;
                    section.data(196).dtTransOffset = 195;

                    ;% px42LoopCtrQGC20220313_P.Saturation10_UpperSat_a
                    section.data(197).logicalSrcIdx = 212;
                    section.data(197).dtTransOffset = 196;

                    ;% px42LoopCtrQGC20220313_P.Saturation10_LowerSat_l
                    section.data(198).logicalSrcIdx = 213;
                    section.data(198).dtTransOffset = 197;

                    ;% px42LoopCtrQGC20220313_P.Saturation11_UpperSat_a
                    section.data(199).logicalSrcIdx = 214;
                    section.data(199).dtTransOffset = 198;

                    ;% px42LoopCtrQGC20220313_P.Saturation11_LowerSat_a
                    section.data(200).logicalSrcIdx = 215;
                    section.data(200).dtTransOffset = 199;

                    ;% px42LoopCtrQGC20220313_P.Gain_Gain_h
                    section.data(201).logicalSrcIdx = 216;
                    section.data(201).dtTransOffset = 200;

                    ;% px42LoopCtrQGC20220313_P.Saturation8_UpperSat_c
                    section.data(202).logicalSrcIdx = 217;
                    section.data(202).dtTransOffset = 201;

                    ;% px42LoopCtrQGC20220313_P.Saturation8_LowerSat_c
                    section.data(203).logicalSrcIdx = 218;
                    section.data(203).dtTransOffset = 202;

                    ;% px42LoopCtrQGC20220313_P.Constant2_Value_k
                    section.data(204).logicalSrcIdx = 219;
                    section.data(204).dtTransOffset = 203;

                    ;% px42LoopCtrQGC20220313_P.Gain5_Gain_l
                    section.data(205).logicalSrcIdx = 220;
                    section.data(205).dtTransOffset = 204;

                    ;% px42LoopCtrQGC20220313_P.Saturation13_UpperSat_p
                    section.data(206).logicalSrcIdx = 221;
                    section.data(206).dtTransOffset = 205;

                    ;% px42LoopCtrQGC20220313_P.Saturation13_LowerSat_j
                    section.data(207).logicalSrcIdx = 222;
                    section.data(207).dtTransOffset = 206;

                    ;% px42LoopCtrQGC20220313_P.Saturation9_UpperSat_d
                    section.data(208).logicalSrcIdx = 223;
                    section.data(208).dtTransOffset = 207;

                    ;% px42LoopCtrQGC20220313_P.Saturation9_LowerSat_c4
                    section.data(209).logicalSrcIdx = 224;
                    section.data(209).dtTransOffset = 208;

                    ;% px42LoopCtrQGC20220313_P.Gain1_Gain_e
                    section.data(210).logicalSrcIdx = 225;
                    section.data(210).dtTransOffset = 209;

                    ;% px42LoopCtrQGC20220313_P.Constant4_Value_l
                    section.data(211).logicalSrcIdx = 226;
                    section.data(211).dtTransOffset = 210;

                    ;% px42LoopCtrQGC20220313_P.Saturation12_UpperSat_d
                    section.data(212).logicalSrcIdx = 227;
                    section.data(212).dtTransOffset = 211;

                    ;% px42LoopCtrQGC20220313_P.Saturation12_LowerSat_j
                    section.data(213).logicalSrcIdx = 228;
                    section.data(213).dtTransOffset = 212;

                    ;% px42LoopCtrQGC20220313_P.Saturation16_UpperSat_p
                    section.data(214).logicalSrcIdx = 229;
                    section.data(214).dtTransOffset = 213;

                    ;% px42LoopCtrQGC20220313_P.Saturation16_LowerSat_i
                    section.data(215).logicalSrcIdx = 230;
                    section.data(215).dtTransOffset = 214;

                    ;% px42LoopCtrQGC20220313_P.Saturation14_UpperSat_n
                    section.data(216).logicalSrcIdx = 231;
                    section.data(216).dtTransOffset = 215;

                    ;% px42LoopCtrQGC20220313_P.Saturation14_LowerSat_a
                    section.data(217).logicalSrcIdx = 232;
                    section.data(217).dtTransOffset = 216;

                    ;% px42LoopCtrQGC20220313_P.Gain3_Gain_p
                    section.data(218).logicalSrcIdx = 233;
                    section.data(218).dtTransOffset = 217;

                    ;% px42LoopCtrQGC20220313_P.Constant6_Value_g
                    section.data(219).logicalSrcIdx = 234;
                    section.data(219).dtTransOffset = 218;

                    ;% px42LoopCtrQGC20220313_P.lambda2_Gain_d
                    section.data(220).logicalSrcIdx = 235;
                    section.data(220).dtTransOffset = 219;

                    ;% px42LoopCtrQGC20220313_P.Saturation1_UpperSat_d
                    section.data(221).logicalSrcIdx = 236;
                    section.data(221).dtTransOffset = 220;

                    ;% px42LoopCtrQGC20220313_P.Saturation1_LowerSat_g
                    section.data(222).logicalSrcIdx = 237;
                    section.data(222).dtTransOffset = 221;

                    ;% px42LoopCtrQGC20220313_P.l2_Gain_i
                    section.data(223).logicalSrcIdx = 238;
                    section.data(223).dtTransOffset = 222;

                    ;% px42LoopCtrQGC20220313_P.Saturation15_UpperSat_k
                    section.data(224).logicalSrcIdx = 239;
                    section.data(224).dtTransOffset = 223;

                    ;% px42LoopCtrQGC20220313_P.Saturation15_LowerSat_h
                    section.data(225).logicalSrcIdx = 240;
                    section.data(225).dtTransOffset = 224;

                    ;% px42LoopCtrQGC20220313_P.Gain6_Gain_f
                    section.data(226).logicalSrcIdx = 241;
                    section.data(226).dtTransOffset = 225;

                    ;% px42LoopCtrQGC20220313_P.Saturation19_UpperSat_bc
                    section.data(227).logicalSrcIdx = 242;
                    section.data(227).dtTransOffset = 226;

                    ;% px42LoopCtrQGC20220313_P.Saturation19_LowerSat_e
                    section.data(228).logicalSrcIdx = 243;
                    section.data(228).dtTransOffset = 227;

                    ;% px42LoopCtrQGC20220313_P.Saturation17_UpperSat_o
                    section.data(229).logicalSrcIdx = 244;
                    section.data(229).dtTransOffset = 228;

                    ;% px42LoopCtrQGC20220313_P.Saturation17_LowerSat_m
                    section.data(230).logicalSrcIdx = 245;
                    section.data(230).dtTransOffset = 229;

                    ;% px42LoopCtrQGC20220313_P.Gain4_Gain_e
                    section.data(231).logicalSrcIdx = 246;
                    section.data(231).dtTransOffset = 230;

                    ;% px42LoopCtrQGC20220313_P.Constant8_Value_p
                    section.data(232).logicalSrcIdx = 247;
                    section.data(232).dtTransOffset = 231;

                    ;% px42LoopCtrQGC20220313_P.Saturation18_UpperSat_c
                    section.data(233).logicalSrcIdx = 248;
                    section.data(233).dtTransOffset = 232;

                    ;% px42LoopCtrQGC20220313_P.Saturation18_LowerSat_g
                    section.data(234).logicalSrcIdx = 249;
                    section.data(234).dtTransOffset = 233;

                    ;% px42LoopCtrQGC20220313_P.Saturation3_UpperSat_i
                    section.data(235).logicalSrcIdx = 250;
                    section.data(235).dtTransOffset = 234;

                    ;% px42LoopCtrQGC20220313_P.Saturation3_LowerSat_g
                    section.data(236).logicalSrcIdx = 251;
                    section.data(236).dtTransOffset = 235;

                    ;% px42LoopCtrQGC20220313_P.l4_Gain_o
                    section.data(237).logicalSrcIdx = 252;
                    section.data(237).dtTransOffset = 236;

                    ;% px42LoopCtrQGC20220313_P.lambda4_Gain_b
                    section.data(238).logicalSrcIdx = 253;
                    section.data(238).dtTransOffset = 237;

                    ;% px42LoopCtrQGC20220313_P.Gain7_Gain_l
                    section.data(239).logicalSrcIdx = 254;
                    section.data(239).dtTransOffset = 238;

                    ;% px42LoopCtrQGC20220313_P.Gain8_Gain_o
                    section.data(240).logicalSrcIdx = 255;
                    section.data(240).dtTransOffset = 239;

                    ;% px42LoopCtrQGC20220313_P.Saturation2_UpperSat
                    section.data(241).logicalSrcIdx = 256;
                    section.data(241).dtTransOffset = 240;

                    ;% px42LoopCtrQGC20220313_P.Saturation2_LowerSat
                    section.data(242).logicalSrcIdx = 257;
                    section.data(242).dtTransOffset = 241;

                    ;% px42LoopCtrQGC20220313_P.e_pitch_InitialValue
                    section.data(243).logicalSrcIdx = 258;
                    section.data(243).dtTransOffset = 242;

                    ;% px42LoopCtrQGC20220313_P.e_pitch1_InitialValue
                    section.data(244).logicalSrcIdx = 259;
                    section.data(244).dtTransOffset = 243;

                    ;% px42LoopCtrQGC20220313_P.e_pitch2_InitialValue
                    section.data(245).logicalSrcIdx = 260;
                    section.data(245).dtTransOffset = 244;

                    ;% px42LoopCtrQGC20220313_P.Constant1_Value_l
                    section.data(246).logicalSrcIdx = 261;
                    section.data(246).dtTransOffset = 245;

                    ;% px42LoopCtrQGC20220313_P.fault_1_Value
                    section.data(247).logicalSrcIdx = 262;
                    section.data(247).dtTransOffset = 246;

                    ;% px42LoopCtrQGC20220313_P.Mixermatrix1_Value
                    section.data(248).logicalSrcIdx = 263;
                    section.data(248).dtTransOffset = 247;

                    ;% px42LoopCtrQGC20220313_P.Gain4_Gain_fc
                    section.data(249).logicalSrcIdx = 264;
                    section.data(249).dtTransOffset = 263;

                    ;% px42LoopCtrQGC20220313_P.fault_2_Value
                    section.data(250).logicalSrcIdx = 265;
                    section.data(250).dtTransOffset = 264;

                    ;% px42LoopCtrQGC20220313_P.fault_3_Value
                    section.data(251).logicalSrcIdx = 266;
                    section.data(251).dtTransOffset = 265;

                    ;% px42LoopCtrQGC20220313_P.fault_4_Value
                    section.data(252).logicalSrcIdx = 267;
                    section.data(252).dtTransOffset = 266;

                    ;% px42LoopCtrQGC20220313_P.Gain8_Gain_o1
                    section.data(253).logicalSrcIdx = 268;
                    section.data(253).dtTransOffset = 267;

                    ;% px42LoopCtrQGC20220313_P.Gain10_Gain
                    section.data(254).logicalSrcIdx = 269;
                    section.data(254).dtTransOffset = 268;

                    ;% px42LoopCtrQGC20220313_P.Gain7_Gain_a
                    section.data(255).logicalSrcIdx = 270;
                    section.data(255).dtTransOffset = 269;

                    ;% px42LoopCtrQGC20220313_P.Gain11_Gain
                    section.data(256).logicalSrcIdx = 271;
                    section.data(256).dtTransOffset = 270;

                    ;% px42LoopCtrQGC20220313_P.Gain9_Gain
                    section.data(257).logicalSrcIdx = 272;
                    section.data(257).dtTransOffset = 271;

                    ;% px42LoopCtrQGC20220313_P.Gain5_Gain_g
                    section.data(258).logicalSrcIdx = 273;
                    section.data(258).dtTransOffset = 272;

                    ;% px42LoopCtrQGC20220313_P.Gain3_Gain_c
                    section.data(259).logicalSrcIdx = 274;
                    section.data(259).dtTransOffset = 273;

                    ;% px42LoopCtrQGC20220313_P.Gain6_Gain_k
                    section.data(260).logicalSrcIdx = 275;
                    section.data(260).dtTransOffset = 274;

                    ;% px42LoopCtrQGC20220313_P.Saturation_UpperSat_e
                    section.data(261).logicalSrcIdx = 276;
                    section.data(261).dtTransOffset = 275;

                    ;% px42LoopCtrQGC20220313_P.Saturation_LowerSat_l
                    section.data(262).logicalSrcIdx = 277;
                    section.data(262).dtTransOffset = 276;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory10_InitialValue
                    section.data(263).logicalSrcIdx = 278;
                    section.data(263).dtTransOffset = 277;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory11_InitialValue
                    section.data(264).logicalSrcIdx = 279;
                    section.data(264).dtTransOffset = 278;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory12_InitialValue
                    section.data(265).logicalSrcIdx = 280;
                    section.data(265).dtTransOffset = 279;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory13_InitialValue
                    section.data(266).logicalSrcIdx = 281;
                    section.data(266).dtTransOffset = 280;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory14_InitialValue
                    section.data(267).logicalSrcIdx = 282;
                    section.data(267).dtTransOffset = 281;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory15_InitialValue
                    section.data(268).logicalSrcIdx = 283;
                    section.data(268).dtTransOffset = 282;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory16_InitialValue
                    section.data(269).logicalSrcIdx = 284;
                    section.data(269).dtTransOffset = 283;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory17_InitialValue
                    section.data(270).logicalSrcIdx = 285;
                    section.data(270).dtTransOffset = 284;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory18_InitialValue
                    section.data(271).logicalSrcIdx = 286;
                    section.data(271).dtTransOffset = 285;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory19_InitialValue
                    section.data(272).logicalSrcIdx = 287;
                    section.data(272).dtTransOffset = 286;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory2_InitialValue
                    section.data(273).logicalSrcIdx = 288;
                    section.data(273).dtTransOffset = 287;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory20_InitialValue
                    section.data(274).logicalSrcIdx = 289;
                    section.data(274).dtTransOffset = 288;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory21_InitialValue
                    section.data(275).logicalSrcIdx = 290;
                    section.data(275).dtTransOffset = 289;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory28_InitialValue
                    section.data(276).logicalSrcIdx = 291;
                    section.data(276).dtTransOffset = 290;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory29_InitialValue
                    section.data(277).logicalSrcIdx = 292;
                    section.data(277).dtTransOffset = 291;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory3_InitialValue
                    section.data(278).logicalSrcIdx = 293;
                    section.data(278).dtTransOffset = 292;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory4_InitialValue
                    section.data(279).logicalSrcIdx = 294;
                    section.data(279).dtTransOffset = 293;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory6_InitialValue
                    section.data(280).logicalSrcIdx = 295;
                    section.data(280).dtTransOffset = 294;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory7_InitialValue
                    section.data(281).logicalSrcIdx = 296;
                    section.data(281).dtTransOffset = 295;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory8_InitialValue
                    section.data(282).logicalSrcIdx = 297;
                    section.data(282).dtTransOffset = 296;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory9_InitialValue
                    section.data(283).logicalSrcIdx = 298;
                    section.data(283).dtTransOffset = 297;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_P.Reset_Value
                    section.data(1).logicalSrcIdx = 299;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_P.attitude_flag_Value
                    section.data(2).logicalSrcIdx = 300;
                    section.data(2).dtTransOffset = 1;

                    ;% px42LoopCtrQGC20220313_P.observer_flag_Value
                    section.data(3).logicalSrcIdx = 301;
                    section.data(3).dtTransOffset = 2;

                    ;% px42LoopCtrQGC20220313_P.position_flag_Value
                    section.data(4).logicalSrcIdx = 302;
                    section.data(4).dtTransOffset = 3;

                    ;% px42LoopCtrQGC20220313_P.Constant2_Value_kf
                    section.data(5).logicalSrcIdx = 303;
                    section.data(5).dtTransOffset = 4;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory_InitialValue_j
                    section.data(6).logicalSrcIdx = 304;
                    section.data(6).dtTransOffset = 5;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory1_InitialValue
                    section.data(7).logicalSrcIdx = 305;
                    section.data(7).dtTransOffset = 6;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory27_InitialValue
                    section.data(8).logicalSrcIdx = 306;
                    section.data(8).dtTransOffset = 7;

                    ;% px42LoopCtrQGC20220313_P.DataStoreMemory30_InitialValue
                    section.data(9).logicalSrcIdx = 307;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_P.ManualSwitch_CurrentSetting
                    section.data(1).logicalSrcIdx = 308;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_P.ManualSwitch_CurrentSetting_i
                    section.data(2).logicalSrcIdx = 309;
                    section.data(2).dtTransOffset = 1;

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
        ;% Auto data (px42LoopCtrQGC20220313_B)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_B.In1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_B.In1_a
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 42;
            section.data(42)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_B.Gain2
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_B.J
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead4
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead4_g
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead4_b
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 4;

                    ;% px42LoopCtrQGC20220313_B.rolldegree
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 5;

                    ;% px42LoopCtrQGC20220313_B.rolldegree_l
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 6;

                    ;% px42LoopCtrQGC20220313_B.rolldegree_c
                    section.data(8).logicalSrcIdx = 9;
                    section.data(8).dtTransOffset = 7;

                    ;% px42LoopCtrQGC20220313_B.pitch
                    section.data(9).logicalSrcIdx = 10;
                    section.data(9).dtTransOffset = 8;

                    ;% px42LoopCtrQGC20220313_B.pitch_a
                    section.data(10).logicalSrcIdx = 11;
                    section.data(10).dtTransOffset = 9;

                    ;% px42LoopCtrQGC20220313_B.roll
                    section.data(11).logicalSrcIdx = 12;
                    section.data(11).dtTransOffset = 10;

                    ;% px42LoopCtrQGC20220313_B.pitch_g
                    section.data(12).logicalSrcIdx = 13;
                    section.data(12).dtTransOffset = 11;

                    ;% px42LoopCtrQGC20220313_B.yaw
                    section.data(13).logicalSrcIdx = 14;
                    section.data(13).dtTransOffset = 12;

                    ;% px42LoopCtrQGC20220313_B.Gain5
                    section.data(14).logicalSrcIdx = 15;
                    section.data(14).dtTransOffset = 13;

                    ;% px42LoopCtrQGC20220313_B.Gain3
                    section.data(15).logicalSrcIdx = 16;
                    section.data(15).dtTransOffset = 14;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead13
                    section.data(16).logicalSrcIdx = 17;
                    section.data(16).dtTransOffset = 15;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead15
                    section.data(17).logicalSrcIdx = 18;
                    section.data(17).dtTransOffset = 16;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead16
                    section.data(18).logicalSrcIdx = 19;
                    section.data(18).dtTransOffset = 17;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead17
                    section.data(19).logicalSrcIdx = 20;
                    section.data(19).dtTransOffset = 18;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead19
                    section.data(20).logicalSrcIdx = 21;
                    section.data(20).dtTransOffset = 19;

                    ;% px42LoopCtrQGC20220313_B.Gain6
                    section.data(21).logicalSrcIdx = 22;
                    section.data(21).dtTransOffset = 20;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead25
                    section.data(22).logicalSrcIdx = 23;
                    section.data(22).dtTransOffset = 21;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead26
                    section.data(23).logicalSrcIdx = 24;
                    section.data(23).dtTransOffset = 22;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead27
                    section.data(24).logicalSrcIdx = 25;
                    section.data(24).dtTransOffset = 23;

                    ;% px42LoopCtrQGC20220313_B.pitch_thrust
                    section.data(25).logicalSrcIdx = 26;
                    section.data(25).dtTransOffset = 24;

                    ;% px42LoopCtrQGC20220313_B.roll_thrust
                    section.data(26).logicalSrcIdx = 27;
                    section.data(26).dtTransOffset = 25;

                    ;% px42LoopCtrQGC20220313_B.yaw_thrust
                    section.data(27).logicalSrcIdx = 28;
                    section.data(27).dtTransOffset = 26;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead41
                    section.data(28).logicalSrcIdx = 29;
                    section.data(28).dtTransOffset = 27;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead34
                    section.data(29).logicalSrcIdx = 30;
                    section.data(29).dtTransOffset = 28;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead35
                    section.data(30).logicalSrcIdx = 31;
                    section.data(30).dtTransOffset = 29;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead36
                    section.data(31).logicalSrcIdx = 32;
                    section.data(31).dtTransOffset = 30;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead37
                    section.data(32).logicalSrcIdx = 33;
                    section.data(32).dtTransOffset = 31;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead38
                    section.data(33).logicalSrcIdx = 34;
                    section.data(33).dtTransOffset = 32;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead39
                    section.data(34).logicalSrcIdx = 35;
                    section.data(34).dtTransOffset = 33;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead48
                    section.data(35).logicalSrcIdx = 36;
                    section.data(35).dtTransOffset = 34;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead49
                    section.data(36).logicalSrcIdx = 37;
                    section.data(36).dtTransOffset = 35;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead55
                    section.data(37).logicalSrcIdx = 38;
                    section.data(37).dtTransOffset = 36;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead8
                    section.data(38).logicalSrcIdx = 39;
                    section.data(38).dtTransOffset = 37;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead9
                    section.data(39).logicalSrcIdx = 40;
                    section.data(39).dtTransOffset = 38;

                    ;% px42LoopCtrQGC20220313_B.y
                    section.data(40).logicalSrcIdx = 41;
                    section.data(40).dtTransOffset = 39;

                    ;% px42LoopCtrQGC20220313_B.y_o
                    section.data(41).logicalSrcIdx = 42;
                    section.data(41).dtTransOffset = 40;

                    ;% px42LoopCtrQGC20220313_B.y_j
                    section.data(42).logicalSrcIdx = 43;
                    section.data(42).dtTransOffset = 41;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_B.output
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_B.NOT
                    section.data(1).logicalSrcIdx = 45;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_B.DataStoreRead12
                    section.data(2).logicalSrcIdx = 46;
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
        nTotSects     = 7;
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
        ;% Auto data (px42LoopCtrQGC20220313_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_DW.obj_n
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_DW.obj_l
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 38;
            section.data(38)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_DW.UD_DSTATE
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTATE
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% px42LoopCtrQGC20220313_DW.UD_DSTATE_b
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTAT_a
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

                    ;% px42LoopCtrQGC20220313_DW.UD_DSTATE_n
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator3_DSTAT_m
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTATE
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

                    ;% px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE_p
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 8;

                    ;% px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTAT_i
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 9;

                    ;% px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTATE_f
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 10;

                    ;% px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator1_DSTAT_g
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 11;

                    ;% px42LoopCtrQGC20220313_DW.DiscreteTimeIntegrator_DSTAT_fj
                    section.data(13).logicalSrcIdx = 15;
                    section.data(13).dtTransOffset = 12;

                    ;% px42LoopCtrQGC20220313_DW.lastSin
                    section.data(14).logicalSrcIdx = 22;
                    section.data(14).dtTransOffset = 13;

                    ;% px42LoopCtrQGC20220313_DW.lastCos
                    section.data(15).logicalSrcIdx = 23;
                    section.data(15).dtTransOffset = 14;

                    ;% px42LoopCtrQGC20220313_DW.start_time_yaw
                    section.data(16).logicalSrcIdx = 24;
                    section.data(16).dtTransOffset = 15;

                    ;% px42LoopCtrQGC20220313_DW.start_time
                    section.data(17).logicalSrcIdx = 25;
                    section.data(17).dtTransOffset = 16;

                    ;% px42LoopCtrQGC20220313_DW.start_time_roll
                    section.data(18).logicalSrcIdx = 26;
                    section.data(18).dtTransOffset = 17;

                    ;% px42LoopCtrQGC20220313_DW.e_pitch
                    section.data(19).logicalSrcIdx = 27;
                    section.data(19).dtTransOffset = 18;

                    ;% px42LoopCtrQGC20220313_DW.e_pitch_roll
                    section.data(20).logicalSrcIdx = 28;
                    section.data(20).dtTransOffset = 19;

                    ;% px42LoopCtrQGC20220313_DW.e_pitch_yaw
                    section.data(21).logicalSrcIdx = 29;
                    section.data(21).dtTransOffset = 20;

                    ;% px42LoopCtrQGC20220313_DW.speed_y
                    section.data(22).logicalSrcIdx = 30;
                    section.data(22).dtTransOffset = 21;

                    ;% px42LoopCtrQGC20220313_DW.pos_x
                    section.data(23).logicalSrcIdx = 31;
                    section.data(23).dtTransOffset = 22;

                    ;% px42LoopCtrQGC20220313_DW.pos_y
                    section.data(24).logicalSrcIdx = 32;
                    section.data(24).dtTransOffset = 23;

                    ;% px42LoopCtrQGC20220313_DW.yaw_speed
                    section.data(25).logicalSrcIdx = 36;
                    section.data(25).dtTransOffset = 24;

                    ;% px42LoopCtrQGC20220313_DW.roll_speed
                    section.data(26).logicalSrcIdx = 37;
                    section.data(26).dtTransOffset = 25;

                    ;% px42LoopCtrQGC20220313_DW.pitch_speed
                    section.data(27).logicalSrcIdx = 38;
                    section.data(27).dtTransOffset = 26;

                    ;% px42LoopCtrQGC20220313_DW.pitch_acc
                    section.data(28).logicalSrcIdx = 39;
                    section.data(28).dtTransOffset = 27;

                    ;% px42LoopCtrQGC20220313_DW.accX
                    section.data(29).logicalSrcIdx = 40;
                    section.data(29).dtTransOffset = 28;

                    ;% px42LoopCtrQGC20220313_DW.roll_acc
                    section.data(30).logicalSrcIdx = 41;
                    section.data(30).dtTransOffset = 29;

                    ;% px42LoopCtrQGC20220313_DW.yaw_acc
                    section.data(31).logicalSrcIdx = 42;
                    section.data(31).dtTransOffset = 30;

                    ;% px42LoopCtrQGC20220313_DW.u1
                    section.data(32).logicalSrcIdx = 43;
                    section.data(32).dtTransOffset = 31;

                    ;% px42LoopCtrQGC20220313_DW.t
                    section.data(33).logicalSrcIdx = 44;
                    section.data(33).dtTransOffset = 32;

                    ;% px42LoopCtrQGC20220313_DW.accY
                    section.data(34).logicalSrcIdx = 45;
                    section.data(34).dtTransOffset = 33;

                    ;% px42LoopCtrQGC20220313_DW.pitch
                    section.data(35).logicalSrcIdx = 46;
                    section.data(35).dtTransOffset = 34;

                    ;% px42LoopCtrQGC20220313_DW.roll
                    section.data(36).logicalSrcIdx = 47;
                    section.data(36).dtTransOffset = 35;

                    ;% px42LoopCtrQGC20220313_DW.yaw
                    section.data(37).logicalSrcIdx = 49;
                    section.data(37).dtTransOffset = 36;

                    ;% px42LoopCtrQGC20220313_DW.speed_x
                    section.data(38).logicalSrcIdx = 50;
                    section.data(38).dtTransOffset = 37;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 51;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_DW.Scope_PWORK_o.LoggedData
                    section.data(2).logicalSrcIdx = 52;
                    section.data(2).dtTransOffset = 1;

                    ;% px42LoopCtrQGC20220313_DW.Scope_PWORK_i.LoggedData
                    section.data(3).logicalSrcIdx = 53;
                    section.data(3).dtTransOffset = 2;

                    ;% px42LoopCtrQGC20220313_DW.Scope_PWORK_ot.LoggedData
                    section.data(4).logicalSrcIdx = 54;
                    section.data(4).dtTransOffset = 3;

                    ;% px42LoopCtrQGC20220313_DW.Scope_PWORK_f.LoggedData
                    section.data(5).logicalSrcIdx = 55;
                    section.data(5).dtTransOffset = 4;

                    ;% px42LoopCtrQGC20220313_DW.Scope_PWORK_b.LoggedData
                    section.data(6).logicalSrcIdx = 56;
                    section.data(6).dtTransOffset = 6;

                    ;% px42LoopCtrQGC20220313_DW.Scope_PWORK_j.LoggedData
                    section.data(7).logicalSrcIdx = 57;
                    section.data(7).dtTransOffset = 7;

                    ;% px42LoopCtrQGC20220313_DW.Scope_PWORK_m.LoggedData
                    section.data(8).logicalSrcIdx = 58;
                    section.data(8).dtTransOffset = 8;

                    ;% px42LoopCtrQGC20220313_DW.Scope1_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 59;
                    section.data(9).dtTransOffset = 11;

                    ;% px42LoopCtrQGC20220313_DW.Scope2_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 60;
                    section.data(10).dtTransOffset = 15;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_DW.systemEnable
                    section.data(1).logicalSrcIdx = 61;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_DW.Subsystem1_SubsysRanBC
                    section.data(1).logicalSrcIdx = 62;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_DW.IfActionSubsystem2_SubsysRanBC
                    section.data(2).logicalSrcIdx = 63;
                    section.data(2).dtTransOffset = 1;

                    ;% px42LoopCtrQGC20220313_DW.IfActionSubsystem1_SubsysRanBC
                    section.data(3).logicalSrcIdx = 64;
                    section.data(3).dtTransOffset = 2;

                    ;% px42LoopCtrQGC20220313_DW.IfActionSubsystem_SubsysRanBC
                    section.data(4).logicalSrcIdx = 65;
                    section.data(4).dtTransOffset = 3;

                    ;% px42LoopCtrQGC20220313_DW.EnabledSubsystem_SubsysRanBC
                    section.data(5).logicalSrcIdx = 66;
                    section.data(5).dtTransOffset = 4;

                    ;% px42LoopCtrQGC20220313_DW.EnabledSubsystem_SubsysRanBC_b
                    section.data(6).logicalSrcIdx = 67;
                    section.data(6).dtTransOffset = 5;

                    ;% px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC
                    section.data(7).logicalSrcIdx = 68;
                    section.data(7).dtTransOffset = 6;

                    ;% px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC_m
                    section.data(8).logicalSrcIdx = 69;
                    section.data(8).dtTransOffset = 7;

                    ;% px42LoopCtrQGC20220313_DW.Subsystem_SubsysRanBC_k
                    section.data(9).logicalSrcIdx = 70;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% px42LoopCtrQGC20220313_DW.attitude_flag
                    section.data(1).logicalSrcIdx = 71;
                    section.data(1).dtTransOffset = 0;

                    ;% px42LoopCtrQGC20220313_DW.observer_flag
                    section.data(2).logicalSrcIdx = 74;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
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


    targMap.checksum0 = 2862294771;
    targMap.checksum1 = 871401741;
    targMap.checksum2 = 998257096;
    targMap.checksum3 = 569271191;

