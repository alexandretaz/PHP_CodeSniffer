<?php
$size = sizeof($array);
$size = count($array);
delete($filepath);
unset($filepath);

// No errors thrown for class methods.
$size = MyClass::sizeof($array);
$size = MyClass::count($array);
MyClass::delete($filepath);
MyClass::unset($filepath);

$size = $class->sizeof($array);
$size = $class->count($array);
$class->delete($filepath);
$class->unset($filepath);

function delete() {}
function unset() {}
function sizeof() {}
function count() {}

trait DelProvider {
  public function delete() {
    //irrelevant
  }
}

class LeftSideTest {
    use DelProvider {
        delete as protected unsetter;
    }
}

class RightSideTest {
    use DelProvider {
        delete as delete;
    }
}

class RightSideVisTest {
    use DelProvider {
        delete as protected delete;
        delete insteadof delete;
    }
}

?>
