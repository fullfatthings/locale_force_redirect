<?php

function locale_force_redirect_settings($form, &$form_state) {
  $form['locale_force_redirect'] = array(
    '#tree' => TRUE,
  );

  foreach(locale_language_list('name', TRUE) as $key => $name) {
    $section = &$form['locale_force_redirect'][$key];
    $section = [
      '#type' => 'fieldset',
      '#title' => $name,
      '#tree' => TRUE,
    ];

    $section['destination_url'] = [
      '#type' => 'textfield',
      '#title' => t('Destination URL'),
      '#description' => t('Enter the full URL of where all requests for this locale should go to.'),
      '#default_value' => locale_force_redirect_destination_url($key),
    ];
  }

  return system_settings_form($form);
}
