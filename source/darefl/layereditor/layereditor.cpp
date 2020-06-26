// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include <darefl/layereditor/layereditor.h>
#include <darefl/model/applicationmodels.h>
#include <darefl/layereditor/layereditoractions.h>
#include <darefl/layereditor/layereditortoolbar.h>
#include <darefl/layereditor/layereditorwidget.h>
#include <darefl/mainwindow/styleutils.h>
#include <QVBoxLayout>

LayerEditor::LayerEditor(ApplicationModels* models, QWidget* parent)
    : QWidget(parent), actions(new LayerEditorActions(models->sampleModel(), this)),
      toolbar(new LayerEditorToolBar(actions)), editor_widget(new LayerEditorWidget(models))
{
    setWindowTitle("Layer editor");

    auto layout = new QVBoxLayout;
    layout->addWidget(toolbar);
    layout->addWidget(editor_widget);
    setLayout(layout);

    actions->setSelectionModel(editor_widget->selectionModel());
}

QSize LayerEditor::sizeHint() const
{
    return StyleUtils::DockSizeHint();
}

QSize LayerEditor::minimumSizeHint() const
{
    return StyleUtils::DockMinimumSizeHint();
}

LayerEditor::~LayerEditor() = default;
