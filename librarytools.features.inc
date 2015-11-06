<?php
/**
 * @file
 * librarytools.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function librarytools_eck_bundle_info() {
  $items = array(
    'librarytools_core_library_librarytools_core_library' => array(
      'machine_name' => 'librarytools_core_library_librarytools_core_library',
      'entity_type' => 'librarytools_core_library',
      'name' => 'librarytools_core_library',
      'label' => 'Drupal core library',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function librarytools_eck_entity_type_info() {
  $items = array(
    'librarytools_core_library' => array(
      'name' => 'librarytools_core_library',
      'label' => 'Drupal core library',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
      ),
    ),
  );
  return $items;
}
