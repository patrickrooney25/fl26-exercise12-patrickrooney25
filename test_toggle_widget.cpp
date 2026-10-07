#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  // Define tests here
  void testButtonTogglesLight();
};

// Implement the tests here
void TestToggleWidget::testButtonTogglesLight(){
    ToggleWidget widget;

    auto button = widget.findChild<QPushButton *>();
    
    QVERIFY(button != nullptr);
    QCOMPARE(widget.isOn(), false);
    
    QTest::mouseClick(button, Qt::LeftButton);
    QCOMPARE(widget.isOn(), true);

    QTest::mouseClick(button, Qt::LeftButton);
    QCOMPARE(widget.isOn(), false);

}

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
