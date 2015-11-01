<?php

/**
 * @file
 * Provides tools related to library functionality provided by Libraries
 * module.
 */

/**
 * Helper function to generate content for cells of libraries table.
 */
function _librarytools_hook_libraries_info_table_cells($library, $libraries, $cell) {
  $output = '';
  switch ($cell) {
    case 'name':
      $output = theme('librarytools_title', array('title' => $libraries[$library]['name']));
      break;

    case 'provider':
      $output = $libraries[$library]['module'];
      break;

    case 'version':
      // For some reason, the library path is sometimes empty, so we have to make
      // double sure we have one.
      if (empty($libraries[$library]['library path'])) {
        $libraries[$library]['library path'] = libraries_get_path($library);
      }
      $output = libraries_get_version($libraries[$library], $libraries[$library]['version arguments']);
      break;

    case 'dependencies':
      $dependencies = array();
      if (!empty($libraries[$library]['dependencies'])) {
        foreach ($libraries[$library]['dependencies'] as $dependency) {
          if (array_key_exists($dependency, $libraries)) {
            $status = t('present');
            $class_name = 'admin-enabled';
          }
          else {
            $status = t('missing');
            $class_name = 'admin-disabled';
          }

          $dependencies[] = theme('librarytools_dependency', array(
            'dependency_name' => $dependency,
            'class_name' => $class_name,
            'status' => $status,
          ));
        }
      }

      $output = theme('librarytools_dependencies', array('dependencies' => $dependencies));
      break;

    case 'files':
      $items = array();
      $type_labels = array(
        'css' => theme('librarytools_title', array('title' => t('CSS'))),
        'js' => theme('librarytools_title', array('title' => t('Javascript'))),
      );

      foreach ($libraries[$library]['files'] as $type => $files) {
        $items[$type]['data'] = $type_labels[$type];
        foreach ($files as $file_name => $file) {
          $items[$type]['children'][] = $file_name;
        }
      }

      $output = theme('item_list', array('items' => $items));
      break;

    case 'path':
      $output = libraries_get_path($library);
      break;

    case 'links':
      // Make the list itself.
      $items = array();

      if (!empty($libraries[$library]['vendor url'])) {
        $items[] = l(t('Vendor URL'), $libraries[$library]['vendor url']);
      }

      if (!empty($libraries[$library]['download url'])) {
        $items[] = l(t('Download URL'), $libraries[$library]['download url']);
      }

      $output = theme('item_list', array(
        'items' => $items,
      ));

      break;
  }

  return $output;
}

/**
 * Helper function to list hook_libraries_info() libraries.
 *
 * (I.e. libraries provided using libraries module function).
 */
function _librarytools_hook_libraries_info_libraries() {
  // Columns:
  //
  // name
  // provider
  // version
  // description
  // files
  // path (?)
  // links
  if ($libraries = libraries_info()) {
    // Make the table header.
    $header = array(
      'name' => array(
        'data' => t('Library name'),
        'sort' => 'asc',
      ),
      'provider' => array(
        'data' => t('Library provider'),
      ),
      'version' => array(
        'data' => t('Library version'),
      ),
      'dependencies' => array(
        'data' => t('Dependencies'),
      ),
      'files' => array(
        'data' => t('Files'),
      ),
      'path' => array(
        'data' => t('Path'),
      ),
      'links' => array(
        'data' => t('Links'),
      ),
    );

    // Assemble the rows.
    $rows = array();

    foreach ($libraries as $library => $properties) {
      $rows[] = array(
        _librarytools_hook_libraries_info_table_cells($library, $libraries, 'name'),
        _librarytools_hook_libraries_info_table_cells($library, $libraries, 'provider'),
        _librarytools_hook_libraries_info_table_cells($library, $libraries, 'version'),
        _librarytools_hook_libraries_info_table_cells($library, $libraries, 'dependencies'),
        _librarytools_hook_libraries_info_table_cells($library, $libraries, 'files'),
        _librarytools_hook_libraries_info_table_cells($library, $libraries, 'path'),
        _librarytools_hook_libraries_info_table_cells($library, $libraries, 'links'),
      );
    }

    // Apologize if there are no libraries :)
    $empty = t('No libraries were found.');
    $caption = t('Summary of libraries declared with <code><a href="http://www.drupalcontrib.org/api/drupal/contributions%21libraries%21libraries.api.php/function/hook_libraries_info/7">hook_libraries_info()</a></code> implementations.');

    $variables = array(
      'header' => $header,
      'rows' => $rows,
      'empty' => $empty,
      'caption' => $caption,
      'attributes' => array(
        'id' => 'library-tools-hook-libraries-info-summary',
      ),
    );

    return theme('table', $variables);
  }
}
