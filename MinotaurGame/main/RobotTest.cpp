//#include <cppunit/extensions/HelperMacros.h>
//#include "Robot.hpp"
//
//class RobotTest : public CppUnit::TestFixture {
//    CPPUNIT_TEST_SUITE(RobotTest);
//    CPPUNIT_TEST(testApplyEffect);
//    CPPUNIT_TEST(testUpdateEffects);
//    CPPUNIT_TEST_SUITE_END();
//
//public:
//    void testApplyEffect() {
//        Robot r(1, 1, 'R');
//        r.applyEffect("shield");
//        CPPUNIT_ASSERT(r.hasEffect("shield"));
//    }
//
//    void testUpdateEffects() {
//        Robot r(1, 1, 'R');
//        r.applyEffect("fogWar");
//        r.updateEffects();
//        // Pretpostavljamo da efekat traje vise poteza, pa je i dalje aktivan
//        CPPUNIT_ASSERT(r.hasEffect("fogWar"));
//    }
//};
//
//CPPUNIT_TEST_SUITE_REGISTRATION(RobotTest);