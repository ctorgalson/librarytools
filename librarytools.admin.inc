<?php

/**
 * @file
 * Provides administration forms to the Library Tools module.
 */

/**
 * Callback for admin/structure/libraries/export.
 */
function librarytools_library_export() {
  $form = array();

  $form['librarytools_export_type'] = array(
    '#options' => array(
      'core' => t('Drupal core library'),
      'libraries' => t('Libraries module library'),
    ),
    '#title' => t('Library type to create'),
    '#type' => 'select',
  );

  $form['librarytools_core_library_export'] = array(
    '#type' => 'fieldset',
    '#title' => t('Drupal core library'),
    '#states' => array(
      'invisible' => array(
        ':input[name="librarytools_export_type"]' => array(
          'value' => 'libraries',
        ),
      ),
    ),
  );

  $form['librarytools_libraries_library_export'] = array(
    '#type' => 'fieldset',
    '#title' => t('Libraries module library'),
    '#states' => array(
      'invisible' => array(
        ':input[name="librarytools_export_type"]' => array(
          'value' => 'core',
        ),
      ),
    ),
  );

  return $form;
}
